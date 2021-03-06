# libft

Первый проект основного обучения (42cursus) школы 42 (школы 21 в России). Описание заданий изложено в документе ***subject*** (с авторскими правами пожалуйста налево). Проект проверен по `norminette` версии 3.3.51.


## Другие работы

В помощь и на вдохновние:

* https://github.com/rchallie/libft

* https://github.com/vvarodi/libft_42

* https://gitgud.io/varnaud/libft

* https://gitlab.com/ranuytte/42_libft


## Тестеры

**Внимание**: тестеры пишут люди, в них могут быть ошибки и скорее всего так и есть.

* https://github.com/alelievr/libft-unit-test

* https://github.com/Tripouille/libftTester

* https://github.com/ska42/libft-war-machine

Не следует "защищать" свои функции только потому, что `libft-unit-test` показывает какие-то взрывы. Функции в общем и не должны проверять входные данные на правильность - это должен делать программист и его обязанность подавать в функцию ровно то, что она "ожидает". Пример: функция `strlen` при подаче NULL приводит к segfault, а не возвращает 0. Причина: NULL - это не строка и даже не пустая строка. Такое поведение вы также должны воспроизводить в вашей функции `ft_strlen.c` без каких-либо "защит".

## Libftx
Дальнейшее расширение библиотеки - https://github.com/stankudrow/libftx (extended).
