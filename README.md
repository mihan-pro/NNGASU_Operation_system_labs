# NNGASU_Operation_system_labs
 
**Задания по операционным системам.**

*Выполнение каждого заданий требует исходного кода программы (программ), скана запуска, а также текстовых пояснений по вопросам.*

***

1) Вывести содержимое из одного файла в стандартный поток вывода с помощью двух программ:
* в одной используются только системные вызовы, 
* в другой – только функции стандартной библиотеки языка С. 
    > Что такое стандартные потоки? 
    >Как вывести содержимое файла в файл, используя готовую программу (не меняя самой программы) данного задания?

2) Скопировать содержимое из одного файла в другой с помощью двух программ:
* в одной используются только системные вызовы, 
* в другой – только функции стандартной библиотеки языка С. 
    >В чём состоит разница между этими двумя способами работы с файлами?



3.1) Выполнить программу вывода из файла в файл с помощью функции system.
    *Для этого использовать программу из задания 2.*

3.2) Выполнить программу вывода из файла в файл с помощью функции fork.
    *Для этого использовать программу из задания 2).*

3.3) Добавить в предыдущие две программы многократный вызов одной и той же программы и сравнить время их работы с помощью time. 
*Пояснить полученный результат.*

4) Запустить на исполнение функцию вывода из файла в файл из задания 2 с системными вызовами с помощью потока. 
Добавить многократный вызов, измерить время работы программы с помощью time. 
Сравнить с результатами аналогичной программы с fork из задания 3. 
*Пояснить результаты.*
<br>
5) Написать программу, передающую содержимое файла другому процессу через именованный канал. Другой процесс должен вывести полученное через канал содержимое в другой файл.
    > Как можно сделать тоже самое, но взаимодействуя через обычный файл, а не через канал?