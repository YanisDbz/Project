typedef struct  s_creature
{
  char			*name;
  int			lvl;
  int			pv;
  int			pvmax;
  int			pm;
  int			pmmax;
  struct s_creature	*prev;
  struct s_creature	*next;
}		t_creature;

typedef struct	s_info
{
  char		*nom;
  t_creature	*team_debut;
  t_creature	*team_fin;
  int		nb;
}		t_info;

t_creature	*getCreature();
char		*my_strdup(const char *str);
void		my_putstr(const char *str);
void      my_putchar(const char c);
int		my_strcmp(const char *s1, const char *s2);
char		*readLine();
void		magicBox(t_info *info, t_creature *creature);
void		helpMe();
void		container(t_info *info, t_creature *creature);
void		my_put_nbr(int n);
void		my_putstr_color(const char *color, const char *str);
int		verifExec(int arg, char **arv, t_info *info);
void		listDetailsContainer(t_info *info);
int		my_getnbr(char *str);
t_creature	*alloc(t_creature *creature);
t_creature	*choixCreature(t_info *info, int n);
void		creatureCapturer(t_creature *creature);
void		slash(t_creature *crea_attaque, t_creature *crea_enemi);
void		fire(t_creature *crea_attaque, t_creature *crea_enemi);
void		gamble(t_creature *crea_attaque, t_creature *crea_enemi);
void		rest(t_creature*crea_attaque);
void		run(t_creature *creaChoisi, t_creature *creature);
char		*entrerCommande(int n);
int		verifCommande(char *str);
