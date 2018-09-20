/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmphephu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:35:22 by mmphephu          #+#    #+#             */
/*   Updated: 2018/06/10 14:35:26 by mmphephu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.hpp"
#include <ncurses.h>
#include <iostream>
#include <sys/time.h>
#include <cstdlib>

Display::Display(): fzero(Hero()), input(ERR), lastInput(ERR), timeFrameCount(0), HEIGHT(SCRHEIGHT), WIDTH(SCRWIDTH), WSTARTX(SCRSTARTX), WSTARTY(SCRSTARTY) {

	init();
}


Display::Display(Display const & src): fzero(Hero()), input(ERR), lastInput(ERR), HEIGHT(SCRHEIGHT), WIDTH(SCRWIDTH), WSTARTX(SCRSTARTX), WSTARTY(SCRSTARTY) {

	init();
	*this = src;
}

Display::~Display() {
	destroyScr();
    endwin();
    std::cout << " Your died! " << std::endl;
}


Display const &	Display::operator=(Display const &ref) {

	if (this != &ref)
	{
		this->input = ref.input;
		this->lastInput = ref.lastInput;
		this->start = ref.start;
		this->now = ref.now;
	}
	return *this;
}

void	Display::createScr() {

    my_win = newwin(HEIGHT, WIDTH, WSTARTY, WSTARTX);
    box(my_win, '=' , '|');
    wrefresh(my_win);
}

void	Display::destroyScr() {
    wborder(my_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wrefresh(my_win);
    clear();
    refresh();
    delwin(my_win);
}

void    Display::shoot(int y) {
    int i;
    for (i = 0; i < 500; i++) {
        if(bullets[i] == NULL)
        {
            bullets[i] = new Bullet(WSTARTX + 6, y);
            return;
        }
    }
}

void    Display::Envadershoot(int x, int y) {
    int i;

    for (i = 0; i < 500; i++)
    {
        if(Envaderbullets[i] == NULL)
        {
            Envaderbullets[i] = new EnvaderBullet(x - 2, y);
            return;
        }
    }
}

void    Display::moveElements(int const input)
{

    fzero.move(input, timeFrameCount);
    if (input == 32)
    {
        shoot(fzero.getY());
    }
    for (int i = 0; i < 50; ++i)
    {
        if (elements[i])
        {
            if (!elements[i]->move(timeFrameCount))
            {
                delete elements[i];
                elements[i] = NULL;
            }
        }
    }
    for (int i = 0; i < 50; ++i)
    {
        if (elements[i])
        {
            if (elements[i] != NULL)
            {
                if ((rand() % 125) == 1)
                   Envadershoot(elements[i]->getX(), elements[i]->getY());
            }
        }
    }
    for (int i = 0; i < 500; ++i)
    {
        if (bullets[i])
        {
            if (!bullets[i]->move(timeFrameCount)){
                delete bullets[i];
                bullets[i] = NULL;
            }
        }
    }
    for (int i = 0; i < 500; ++i)
    {
        if (Envaderbullets[i])
        {
            if (!Envaderbullets[i]->move(timeFrameCount))
            {
            	delete Envaderbullets[i];
                Envaderbullets[i] = NULL;
            }
        }
    }
}

void    Display::printScreen() {

    mvprintw(4, 103, "POINTS ");
    mvprintw(4, 97, "%d", score);

    mvprintw(4, 4, "%d", fzero.life);
    mvprintw(4, 7, "LIFE");
    fzero.toPrint();
    for (int i = 0; i < 50; ++i)
    {
        if (elements[i])
            elements[i]->toPrint();
    }
    for (int i = 0; i < 500; ++i)
    {
      if (bullets[i])
            bullets[i]->toPrint();  
    }
    for (int i = 0; i < 500; ++i)
    {
      if (Envaderbullets[i])
            Envaderbullets[i]->toPrint();  
    }
}

void    Display::initArray() {

    for (int i = 0; i < 50; ++i)
    {
        if (elements[i])
            elements[i] = NULL;
    }
}

void    Display::createEnvader(int timeFrameCount) {
    if (timeFrameCount % 20 == 0){
        int y = (rand() % 18) + 6;
        for (int i = 0; i < 500; ++i)
            {
                if (!elements[i]) {
                    elements[i] = new Envader(WIDTH + SCRSTARTX - 1, y);
                    return;
                }
            }
    }
}

void    Display::initBullets() {

    for (int i = 0; i < 500; ++i)
        elements[i] = new Bullet();
}

void    Display::initEnvaderBullets() {

    for (int i = 0; i < 500; ++i)
        elements[i] = new EnvaderBullet();
}

void    Display::initArray2() {
    for (int i = 0; i < 500; ++i)
    {
        if (bullets[i])
            bullets[i] = NULL;
        if (Envaderbullets[i])
            Envaderbullets[i] = NULL;
    }
}

void	Display::init() {

    initArray();
	initscr();
    initArray2();
    noecho();
    curs_set(false);
    timeout(0);
    cbreak();
    keypad(stdscr, true);

    gettimeofday(&start, NULL);
    refresh();
    createScr();
    printScreen();
}

unsigned int    Display::timediff(timeval t1, timeval t2) {

    return ((t2.tv_sec * 1000000 + t2.tv_usec) - (t1.tv_sec * 1000000 + t1.tv_usec));
}

int     Display::collide()
{
    for (int i = 0; i < 50; ++i)
    {
        if (elements[i] && fzero.colision(elements[i]))
            fzero.life--;
        if (fzero.life < 0)
            return (1);
    }
    for (int i = 0; i < 500; ++i)
    {
        if (Envaderbullets[i] && fzero.colision(Envaderbullets[i]))
        {
            delete Envaderbullets[i];
            Envaderbullets[i] = NULL;
            fzero.life--;
        }
        if (fzero.life < 0)
            return (1);
    }

    for (int j = 0; j < 500; ++j)
    {
        for (int k = 0; (k < 50 && bullets[j]) ; ++k)
        {
            if (elements[k] && bullets[j]->colision(elements[k]))
            {
                delete bullets[j];
                bullets[j] = NULL;
                delete elements[k];
                elements[k] = NULL;
                score += 25;
            }
        }
    }
    return (0);
}

void	Display::play() {

    score = 0;
    input = getch();
    while (input != 27){
        input = getch();
        if (input != ERR) {
            lastInput = input;
        }
        gettimeofday(&now, NULL);      
        if (timediff(start, now) >= (1000000 / 24)) {
            destroyScr();
            createScr();
            createEnvader(timeFrameCount);
            moveElements(lastInput);
            printScreen();
            if (collide())
                return ;
            lastInput = ERR;
            start = now;
            timeFrameCount++;
        }
    }
}
