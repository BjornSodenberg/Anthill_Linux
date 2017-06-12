# Anthill_Linux
Инструкция по установке и запуску
Шаг 1.
Запустите консоль в родительской папке проекта (рис. 1.)
рис. 1. Содержимое родительской папки проекта. (Содержимое может отличаться)

Шаг 2.
В консоли наберите команду make 

nameofusr@nameofusr:~…/Anthill_Linux$ make

После завершения сборки проекта, переходите к шагу “3”

Шаг 3.

Зайдите через консоль в папку bin/Tests/

nameofusr@nameofusr:~…/Anthill_Linux$ cd bin/Tests

И в этой папке запустите приложение

nameofusr@nameofusr:~…/Anthill_Linux/bin/Tests$ ./Menutest



В случае ошибки при запуске программы
Находясь в папке “…/Anthill_Linux/bin/Tests” выполните команду sudo chmod +x ./Menutest
