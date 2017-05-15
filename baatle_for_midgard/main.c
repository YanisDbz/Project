#include <stdlib.h>
#include <time.h>
#include "struct.h"


char	*entrerCommande(int n)
{
  char	*str;
  str = malloc(sizeof(str) * 50);
  if (str == NULL)
    return (NULL);
  if (n == 1)
    {
      my_putstr_color("BYELLOW", "magic catch : help me : quit\n");
      my_putstr_color("BCYAN", "Quel est ton ordre $>");
      str = readLine();
      while ((my_strcmp(str, "magic catch") != 0)&&(my_strcmp(str, "help me") != 0)&&(my_strcmp(str, "quit") != 0))
	{
    my_putstr_color("BYELLOW", "magic catch : help me : quit\n");
    my_putstr_color("BCYAN", "Quel est ton ordre $>");
	  str = readLine();
	}
    }
  else if (n == 2)
    {
      my_putstr_color("BYELLOW", "team : you are the chosen one : let's fight : quit\n");
      my_putstr_color("BCYAN", "Quel est ton ordre $>");
      str = readLine();
      while ((my_strcmp(str, "team") != 0)&&(my_strcmp(str, "you are the chosen one") != 0) 
        &&(my_strcmp(str, "let's fight") != 0)&&(my_strcmp(str, "quit") != 0))
	{
	  my_putstr_color("BYELLOW", "team : you are the chosen one : let's fight : quit\n");
    my_putstr_color("BCYAN", "Quel est ton ordre $>");
	  str = readLine();
	}
    }
  else if(n == 6)
    {
      my_putstr_color("BYELLOW", "slash : fire : gamble : rest : magic catch : quit\n");
      my_putstr_color("BCYAN", "Quel est ton ordre $>");
      str = readLine();
      while ((my_strcmp(str, "slash") != 0) && (my_strcmp(str, "fire") != 0) && (my_strcmp(str, "gamble") != 0) 
        &&(my_strcmp(str, "rest") != 0) && (my_strcmp(str, "quit") != 0))
	{
    my_putstr_color("BYELLOW", "slash : fire : gamble : rest : magic catch : quit\n");
	  my_putstr_color("BCYAN", "Quel est ton ordre $>");
	  str = readLine();
	}
    }
  else
    my_putstr_color("red", "Entre une commande quon connait BAKA\n");
  return (str);
}

int	verifCommande(char *str)
{
  if (my_strcmp("magic catch", str) == 0)
    {
      free(str);
      return (1);
    }
  else if (my_strcmp("help me", str) == 0)
    {
      free(str);
      return (2);
    }
  else if (my_strcmp("quit", str) == 0)
    {
      free(str);
      return (3);
    }
  else if (my_strcmp("team", str) == 0)
    {
      free(str);
      return (4);
    }
  else if (my_strcmp("you are the chosen one", str) == 0)
    {
      free(str);
      return (5);
    }
  else if (my_strcmp("let's fight", str) == 0)
    {
      free(str);
      return (6);
    }
  else if (my_strcmp("slash", str) == 0)
    {
      free(str);
      return (7);
    }
  else if (my_strcmp("fire", str) == 0)
    {
      free(str);
      return (8);
    }
  else if (my_strcmp("gamble", str) == 0)
    {
      free(str);
      return (9);
    }
  else if (my_strcmp("rest", str) == 0)
    {
      free(str);
      return (10);
    }  
  return (0);
}

int	verifExec(int arg, char **arv, t_info *info)
{
  if (arg < 2)
    {
      my_putstr_color("BRED", "Le nom de votre heros !\n[a.out] -n Yayalebest\n");
      free(info);
      return (0);
    }
  else if (arg > 1 && arg < 4)
    {
      if (my_strcmp(arv[1], "-n") == 0 && arg > 2)
	{
	  info->nom = my_strdup(arv[2]);
	  my_putstr("\033[H\033[2J");
	  my_putstr("Salut ");
	  my_putstr(info->nom);
	  my_putstr("\n");
	  my_putstr_color("BMAGENTA", "Une créature est apparue quel est on ordre ");
    my_putstr_color("BMAGENTA", info->nom);
    my_putchar('\n');
	  return (1);
	}
      else
	{
	  my_putstr_color("BRED", "Entrer votre nom !");
    my_putchar('\n');
	  free(info);
	  return (0);
	}
    }
  free(arv);
  free(*arv);
  return (0);
}

int	verifChoix(t_info *info)
{
  char		*str;
  int		nb;
  int		i;
  t_creature	*tmp = NULL;

  tmp = alloc(tmp);
  tmp = info->team_debut;
  i = 1;
  nb = 420000;
  while (nb > info->nb || nb <= 0)
    {
      while (tmp != NULL)
	{
	  my_putstr("tapez ");
	  my_put_nbr(i);
	  my_putstr(" pour ");
	  my_putstr(tmp->name);
	  tmp = tmp->next;
	}
      my_putstr("\n");
      my_putstr_color("BCYAN", "Quel est ton ordre $>");
      str = readLine();
      nb = my_getnbr(str);
    }
  free(tmp);
  return (nb);
}

int	main(int argc, char **argv)
{
  int		nbChoix;
  int		ok;
  int		flags;
  int		verifComm;
  t_info	*info = NULL;
  t_creature	*creature = NULL;
  t_creature	*creaChoisi = NULL;
  t_creature	*creatureEnemie = NULL;

  creatureEnemie = alloc(creatureEnemie);
  creature = alloc(creature);
  flags = 1;
  info = malloc(sizeof(*info));
  if (info == NULL)
    return (0);
  info->team_debut = NULL;
  info->team_fin = NULL;
  info->nb = 0;
  srand(time(NULL));
  ok = verifExec(argc, argv, info);
  if (ok == 0)
    return (0);
  while (flags)
    {
      while (info->nb < 1 && flags)
	{
	  creature = getCreature();
	  verifComm = verifCommande(entrerCommande(1));
	  if (verifComm == 1)
	    {
	      magicBox(info, creature);
	      if (info->nb >= 1)
          my_putstr_color("BGREEN", "Vous avez assez de creature pour commencer l'aventure !\n");
        else
          my_putstr_color("BBLUE", "Une nouvelle creature est apparue\n");
	    }
	  else if (verifComm == 2)
	    {
	      helpMe();
	      free(creature);
	      creature = NULL;
	      creature = alloc(creature);
	      creature = getCreature();
        /*my_putstr_color("BRED", info->nom);
        my_putstr_color("BRED", " une nouvelle créature est apparue\n");*/
	    }
	  else if (verifComm == 3)
	    flags = 0;
	}
      while (info->nb >= 1 && flags)
	{
	 /*my_putstr_color("BRED", info->nom);
    my_putstr_color("BRED", " une nouvelle créature est apparue\n");*/
	  verifComm = verifCommande(entrerCommande(2));
	  if (verifComm == 4)
	    listDetailsContainer(info);
	  else if (verifComm == 5)
	    {
	      free(creaChoisi);
	      creaChoisi = NULL;
	      creaChoisi = alloc(creaChoisi);
	      nbChoix = verifChoix(info);
	      creaChoisi = choixCreature(info, nbChoix);
	      creatureCapturer(creaChoisi);
	    }
	  else if (verifComm == 6)
	    {
	      if (creaChoisi == NULL)
		{
      my_putstr_color("BRED", info->nom);
		  my_putstr_color("BRED", " avant de te battre choisi ta créture BAKA\n");
		  continue;
		}
	      else
		{
		  free(creatureEnemie);
		  creatureEnemie = NULL;
		  creatureEnemie = getCreature();
		  run(creaChoisi, creatureEnemie);
		  creaChoisi = NULL;
		}
	    }
	  else if (verifComm == 3)
	    flags = 0;
	}
    }
  free(info);
  free(creature);
  free(creatureEnemie);
  free(creaChoisi);
  my_putstr_color("BBLUE", "ADIEU ");
  my_putchar('\n');
  return (0);
}
