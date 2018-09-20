/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmphephu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:35:51 by mmphephu          #+#    #+#             */
/*   Updated: 2018/06/10 14:35:56 by mmphephu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

#define SCRHEIGHT 20
#define SCRWIDTH 100
#define SCRSTARTX 5
#define SCRSTARTY 6

#include "Character.hpp"
#include "Hero.hpp"
#include "Envader.hpp"
#include "Bullet.hpp"
#include "EnvaderBullet.hpp"
#include <ncurses.h>
#include <sys/time.h>

class Display
{

public:

	Display();
	Display(Display const &);
	~Display();

	Display const &	operator=(Display const &);
	void	createScr();
	void	destroyScr();
	void	play();

private:

	Character* elements[50];
	Character* bullets[500];
	Character* Envaderbullets[500];
	Hero		fzero;
	int				input;
	int				lastInput;
	int 			score;
	unsigned long	timeFrameCount;
	struct timeval	start;
	struct timeval	now;
	WINDOW			*my_win;
	const int		HEIGHT;
	const int		WIDTH;
	const int		WSTARTX;
	const int		WSTARTY;

	void	init();
	void	printScreen();
	void	initArray();
	void	initArray2();
	void	initEnvader();
	void	initBullets();
	void	initEnvaderBullets();
	void	shoot(int y);
	void	Envadershoot(int x, int y);
	void	createEnvader(int timeFrameCount);
	void	moveElements(int const input);
	unsigned int 	timediff(timeval t1, timeval t2);
	int		collide();
};

#endif

