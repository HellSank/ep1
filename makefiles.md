# Explicação sobre MakeFiles

- Video de introdução aos [makefiles](https://www.youtube.com/watch?v=6Gw1rNyTJWA&list=LL&index=1&ab_channel=CalebCurry).
- O que significa a função [wildcard](https://www.gnu.org/software/make/manual/html_node/Wildcard-Function.html).
- Blog falando sobre [wildcard](https://earthly.dev/blog/using-makefile-wildcards/).


## Variáveis automáticas:
- O que significa '$@' : É o nome do target, arquivo gerado.
- O que significa '$<' : É o nome do primeiro pré requisito.
- O que significa '$^' : É o nome de todos os pré requisitos.

## all: $(SRCFILES:src/%.cpp=obj/%.o)

Faz a substituição do nome do arquivo .cpp em .o, ou seja:
cada arquivo .cpp gera um arquivo .o .

- O que significa '%' : pegue o nome.

## Notas

Target -> é o que está antes de dois pontos.

By defining a rule inside your Makefile with the '%' character,
you can refer to the pattern inside the target by using the 
character sequence '$*'.
