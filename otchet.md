Поиск подстроки в строки работает в два цикла и находит совпадения символов, сравнивая строки посимвольно

Алгоритм Робина Карпа использует хэш функции, суть в том что сравнивать два хеша(строка и подстрока) гораздо быстрее
и дешевле чем сравнивать две строки посимвольно
Поэтому алгоритм Рабина-Карпа должен вычислить хэш-значения для следующих строк.
1) Сам шаблон.
2) Все подстроки текста длиной m.

Поскольку нам нужно эффективно вычислить хэш-значения для всех подстрок текста размером m, мы должны иметь хэш-функцию,
которая обладает следующим свойством.
Хэш при следующем сдвиге должен эффективно вычисляться из текущего хэш-значения и следующего символа в тексте
Хэш-функция, предложенная Рабином и Карпом, вычисляет целочисленное значение.
Целочисленное значение для строки - это числовое значение строки.

Суть алгоритма Кнутта-Мориса-Пратта
Алгоритм KMP используется для поиска "подстроки" в "строке". Этот алгоритм сравнивает символ за символом слева направо.
Но всякий раз, когда возникает несоответствие, он использует предварительно обработанную функцию ,
чтобы пропустить сравнение символов при поиске.

Вывод: На мой взгляд алгоритм Кнутта-Мориса-Пратта является не самым сложным из всех алгоритмов, но наиболее эффективным.