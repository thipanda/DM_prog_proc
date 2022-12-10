#Makefile all compile les programmes et créer un executable "modele" ainsi que les fichiers binaires
#Makefile clean enleve tout les fichiers binaires générés à la compilation ainsi que les fichiers créer par les éditeurs de textes
#Makefile save sauvegarde les fichier source dans save

COUNT=$(shell ls -1 $(BINDIR)*.o 2>/dev/null | wc -l)
BAK=$(shell ls -1 $(BINDIR)*.bak 2>/dev/null | wc -l)
OLD=$(shell ls -1 $(BINDIR)*.old 2>/dev/null | wc -l)
HASHTAG=$(shell ls -1 $(BINDIR)*."*~" 2>/dev/null | wc -l)
EVERYONE=$(shell ls -1 $(BINDIR)"\#"*"\#" 2>/dev/null | wc -l)

#emplacement des fichiers
SRCDIR:=./src/
BINDIR:=./bin/
SAVEDIR:=./save/
DOCDIR:=./doc/

Input:=$(wildcard $(SRCDIR)/*.c $(SRCDIR)/*.h)
Output:=$(patsubst $(SRCDIR)/%, $(SAVEDIR)/%, $(Input:Input=Output))


CC=gcc -Wall
RM=rm -i
SRC=$(shell ls $(SRCDIR)*.c)
HEAD=$(shell ls $(SRCDIR)*.h)
OBJ=$(subst $(SRCDIR), $(BINDIR),$(SRC:.c=.o))

#nom du programme
PROG=modele
CP=cp -rf

all : $(BINDIR)$(PROG)

$(BINDIR)$(PROG) : $(OBJ)
	$(CC) $(OBJ) -o $@

$(BINDIR)%.o : $(SRCDIR)%.c
	$(CC) -c $^ -o $@

.PHONY : clean

.PHONY : save




save : $(Output)
$(SAVEDIR)%.c : $(SRCDIR)%.c
	$(CP) $< $@

$(SAVEDIR)%.h : $(SRCDIR)%.h
	$(CP) $< $@


clean :

ifneq (${COUNT},0)
	$(RM) $(BINDIR)*.o
endif
ifneq (${BAK},0)
	$(RM) $(BINDIR)*.bak
endif
ifneq (${OLD},0)
	$(RM) $(BINDIR)*.old
endif
ifneq (${EVERYONE},0)
	$(RM) $(BINDIR)*."*~"
endif
ifneq (${HASHTAG},0)
	$(RM) $(BINDIR)"#"*"#"
endif
