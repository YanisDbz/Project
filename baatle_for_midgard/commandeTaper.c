#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"

void    helpMe()
{
  my_putstr_color("BRED", "La creature te charge !!!! Re commence vite !\n");
}

void	creatureCapturer(t_creature *creature)
{
  my_putstr_color("BGREEN", "Vous avez capturé : ");
  my_putstr(creature->name);
  my_putchar('\n');
  my_putstr_color("BGREEN", "LVL : ");
  my_put_nbr(creature->lvl);
  my_putchar('\n');
  my_putstr_color("BGREEN", "PV : ");
  my_put_nbr(creature->pv);
  my_putchar('\n');
  my_putstr_color("BGREEN", "PVMAX : ");
  my_put_nbr(creature->pvmax);
  my_putchar('\n');
  my_putstr_color("BGREEN", "PM : ");
  my_put_nbr(creature->pm);
  my_putchar('\n');
  my_putstr_color("BGREEN", "PMAX : ");
  my_put_nbr(creature->pmmax);
  my_putchar('\n');

}

void	magicBox(t_info *info, t_creature *creature)
{
  int	alea;
  srand(time(NULL));
  alea = rand() % 3;
  if (alea == 0)
    {
      my_putstr_color("BGREEN", "Capturé\n");
      container(info, creature);
      creatureCapturer(creature);
    }
  else
    {
      my_putstr_color("BRED", "Manqué !\n");
      helpMe();
    }
}
