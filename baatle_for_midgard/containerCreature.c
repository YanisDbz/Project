#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

void	container(t_info *info, t_creature *creature)
{
  if (info->team_fin == NULL)
  {
    info->team_debut = creature;
    info->team_fin = creature;
    creature->prev = NULL;
    creature->next = NULL;
  }
  else if (creature == NULL)
    return ;
  else if (info->team_fin != NULL)
  {
    info->team_fin->next = creature;
    creature->prev = info->team_fin;
    info->team_fin = creature;
    info->team_fin->next = NULL;
  }
  info->nb++;
}

void	listDetailsContainer(t_info *info)
{
  t_creature *tmp = NULL;
  tmp = alloc(tmp);
  tmp = info->team_debut;
  my_putstr_color("BBLUE", "Vous avez ");
  my_put_nbr(info->nb);
  my_putstr_color("BBLUE", " creatures\n");
  while (tmp != NULL)
    {
      my_putstr_color("BCYAN", "Vos crétures capturés sont : ");
      my_putstr(tmp->name);
      my_putchar('\n');
      my_putstr_color("BCYAN", "PV : ");
      my_put_nbr(tmp->pv);
      my_putchar('\n');
      my_putstr_color("BCYAN", "PVMAX :");
      my_put_nbr(tmp->pvmax);
      my_putchar('\n');
      my_putstr_color("BCYAN", "PM :");
      my_put_nbr(tmp->pm);
      my_putchar('\n');
      my_putstr_color("BCYAN", "PMAX :");
      my_put_nbr(tmp->pmmax);
      my_putchar('\n');
      tmp = tmp->next;
    }
  free(tmp);
}

t_creature	*alloc(t_creature *creature)
{
  creature = malloc(sizeof(creature));
  if (creature == NULL)
    return (NULL);
  return (creature);
}

t_creature	*choixCreature(t_info *info, int n)
{
  int i = 0;
  t_creature *creaChoisi = NULL;
  creaChoisi = alloc(creaChoisi);
  creaChoisi = info->team_debut;
  while (i < n - 1)
      creaChoisi = creaChoisi->next;
  return (creaChoisi);
}
