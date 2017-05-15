/*
** attak.c for  in /home/piscine/bfmEnC
** 
** Made by BENKRIZI El harag
** Login   <benkri_e@etna-alternance.net>
** 
** Started on  Fri May 12 19:41:51 2017 BENKRIZI El harag
** Last update Sat May 13 00:03:11 2017 BENKRIZI El harag
*/

#include <stdlib.h>
#include <time.h>
#include "struct.h"


void  slash(t_creature *crea_attaque, t_creature *crea_ennemi)
{
  my_putstr_color("yellow", "ATTAQUE SLASH\n");
  my_putstr_color("green", "Vous avez enlever 15 pv à la cible\n");
  crea_ennemi->pv = crea_ennemi->pv -15;
  if(crea_ennemi->pv <= 0)
    {
      my_putstr_color("BGREEN", "La creature a ete abbatue !!! \n");
    }
  else
    {
      my_putstr_color("BGREEN", "PV : ");
      my_put_nbr(crea_ennemi->pv);
      my_putstr("\n");
    }
  my_putstr_color("BRED", "Vous perdez 3 pm\n");
  crea_attaque->pm = crea_attaque->pm - 3;
  if(crea_attaque->pm < 0)
    {
      my_putstr_color("BRED", "Vous ne pouvez plus bouger !\n");
    }
  else
    {
      my_putstr_color("BGREEN", "Vos PM : ");
      my_put_nbr(crea_attaque->pm);
      my_putstr("\n");
    }
}

void  fire(t_creature *crea_attaque, t_creature *crea_ennemi)
{
  my_putstr_color("BYELLOW", "    ATTAQUE FIRE\n");
  my_putstr_color("BGREEN", "Vous avez enlever 30 pv à la cible\n");
  crea_ennemi->pv = crea_ennemi->pv -30;
  if(crea_ennemi->pv <= 0)
    {
      my_putstr_color("BGREEN", "La creature a ete abbatue !!! \n");
    }
  else
    {
      my_putstr_color("BGREEN", "PV : ");
      my_put_nbr(crea_ennemi->pv);
      my_putstr("\n");
    }
  my_putstr_color("BRED", "Voous perdez 7 pm\n");
  crea_attaque->pm = crea_attaque->pm - 7;
  if(crea_attaque->pm < 0)
    {
      my_putstr_color("BRED", "Vous ne pouvez plus bouger !\n");
    }
  else
    {
      my_putstr_color("BGREEN", "Vos PM : ");
      my_put_nbr(crea_attaque->pm);
      my_putstr("\n");
    }
}

void  gamble(t_creature *crea_attaque, t_creature *crea_ennemi)
{
  int rld;
  int rnd;
  srand(time(NULL));
  rnd = rand() % 20;
  rld = rand() % 2;
  my_putstr_color("yellow", "ATTAQUE FIRE\n");
  if (rld == 0)
    {
      my_putstr_color("BGREEN", "Vous avez enlever ");
      my_put_nbr(rnd);
      my_putstr_color("BGREEN", " PV a la cible");
      crea_ennemi->pv = crea_ennemi->pv - rnd;
      if(crea_ennemi->pv <= 0)
	{
	  my_putstr_color("BGREEN", "La creature a ete abbatue !!! \n");
	}
      else
	{
	  my_putstr_color("BGREEN", "PV : ");
	  my_put_nbr(crea_ennemi->pv);
	  my_putstr("\n");
	}
    }
  else if (rld == 1)
    {
      my_putstr_color("BRED" , "L'ennemie vous a enlever PV" );
      my_put_nbr(rnd);
      my_putstr("\n");
      crea_attaque->pv = crea_attaque->pv - rnd;
      if(crea_attaque->pv <= 0)
	{
	  my_putstr_color("BGREEN", "La creature a ete abbatue !!! \n");
	}
      else
	{
	  my_putstr_color("BGREEN", "PV : ");
	  my_put_nbr(crea_attaque->pv);
	  my_putstr("\n");
	}
    }
}

void  rest(t_creature *crea_attaque)
{
  my_putstr_color("BGREEN", "Recuperation de 10 PM\n\n");
  crea_attaque->pm = crea_attaque->pm + 10;
  my_putstr_color("BGREEN", " PM : ");
  my_put_nbr(crea_attaque->pm);
}

void  run(t_creature *creaChoisi, t_creature *creature)
{
  int lol;
  int verifComm;
  while (creaChoisi->pv > 0 && creature->pv > 0 && creaChoisi->pm > 0 && creature->pm > 0)
    {
      my_putstr_color("BGREEN", "We are IN FIGHT MODE BITCHIES\n");
      my_putstr_color("BGREEN", "Quels sont vos ordres ????????\n");
      verifComm = verifCommande(entrerCommande(6));
      if (verifComm == 7)
	{
	  srand(time(NULL));
	  lol = rand() % 4;
	  slash(creaChoisi, creature);
	  if (creature->pv > 0 && creature->pm > 0)
	    {
	      if(lol == 0)
		slash(creature, creaChoisi);
	      else if (lol == 1)
		fire(creature, creaChoisi);
	      else if (lol == 2)
		gamble(creature, creaChoisi);
	      else if (lol == 3)
		rest(creature);
	    }
	}
      if (verifComm == 8)
	{
	  srand(time(NULL));
	  lol = rand() % 4;
	  fire(creaChoisi, creature);
	  if(lol == 0)
	    slash(creature, creaChoisi);
	  else if (lol == 1)
	    fire(creature, creaChoisi);
	  else if (lol == 2)
	    gamble(creature, creaChoisi);
	  else if (lol == 3)
	    rest(creature);
	}
      if (verifComm == 9)
	{
	  srand(time(NULL));
	  lol = rand() % 4;
	  gamble(creaChoisi, creature);
	  if(lol == 0)
	    slash(creature, creaChoisi);
	  else if (lol == 1)
	    fire(creature, creaChoisi);
	  else if (lol == 2)
	    gamble(creature, creaChoisi);
	  else if (lol == 3)
	    rest(creature);
	}
      if (verifComm == 10)
	{
	  srand(time(NULL));
	  lol = rand() % 4;
	  rest(creaChoisi);
	  if(lol == 0)
	    slash(creature, creaChoisi);
	  else if (lol == 1)
	    fire(creature, creaChoisi);
	  else if (lol == 2)
	    gamble(creature, creaChoisi);
	  else if (lol == 3)
	    rest(creature);
	}
    }
  
  
}
