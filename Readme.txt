
Код OpenGL на Маке транслируется в Metal через Rosetta, т.к МакОсь не умеет работать с OpenGL.

Не пытайтесь настроить проект под OpenGL в Xcode. Xcode обращается к компилятору g++, который не умеет обращаться к внутренним фреймворкам МакОСИ таким как Cocoa и IOkiit, без которых никакой код, который обращается к видеодрайверу не заведется. Чтобы все завелось необходимо обращаться к компилятору Apple Clang, ибо он умеет работать с внутренними фреймами системы и транслятором Rosetta.

1. если Мак на Intel процессоре (т.е Х86_64) тогда libArm поменять на libX86 в Makefile'е (7 строка кода)

Структура:
    Скомпилированные бинарники хранятся в bin

    !!!!!!!! по пути /vendors/GLFW/ есть две папки для Intel Маков и Arm Маков. Обязательно смотри пункт 1 

    main.cpp хранится только в корне папки vendors (не советую его перемещать, т.к Apple Clang требует соблюдения опредленной иерархии при работе с проектами, где есть прекомпилированная библиотека)

Как билдить и запускать бинарник:

    !!!Обязательно переключить Bash на zsh (просто выполнить команду zsh), важный аспект на Intel Маках, т.к по умолчанию они используют Bash. ARM Маки уже по умолчанию используют zsh.
    Если уже стоит zsh, переключать командную оболочку не нужно. В VScode будет написано какая командная оболочка используется в данный момент


    Для удобства в VSCode открыть отдельный терминал Terminal -> New Terminal
    В терминале выполнить команду make 
    чтобы запустить бинарник ./bin/myApp в терминале
    !!rm -rf можно не делать
    

