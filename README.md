# Circular Buffer https://en.wikipedia.org/wiki/Circular_buffer

![image](https://github.com/PopekaDS/CircularBuffer/assets/70101127/302159b3-ca60-47cb-937b-c69a574fa882)

Кольцевой буфер, или циклический буфер (англ. ring-buffer) — это структура данных, использующая единственный буфер фиксированного размера таким образом, как будто бы после последнего элемента сразу же снова идет первый. Такая структура легко предоставляет возможность буферизации потоков данных.
Иллюстрация визуально показывает, что у буфера нет настоящего конца. Тем не менее, поскольку физическая память никогда не делается закольцованной, обычно используется линейное представление

Кольцевой буфер создается пустым, с некоторой заранее определённой длиной. Например, это восьмиэлементный буфер:

![image](https://github.com/PopekaDS/CircularBuffer/assets/70101127/580b6b90-2365-44d7-872b-929e224eddda)

Предположим, что в буфер записывается «6» (в кольцевом буфере точная начальная ячейка не имеет значения):

![image](https://github.com/PopekaDS/CircularBuffer/assets/70101127/60c9c79a-ee39-4def-9dd7-6146bd9bd0e0)

Затем предположим, что после «6» были добавлены ещё элементы в конец — «7» и «8»:

![image](https://github.com/PopekaDS/CircularBuffer/assets/70101127/b43baac9-a560-4868-ac96-acea539c3c4a)

Затем в начало перед «6» были добавлены ещё элементы - «5», «4» и «3»: 

![image](https://github.com/PopekaDS/CircularBuffer/assets/70101127/30cbf755-bd2a-4ade-82a7-7dff3e2cec33)

После этого, удаляяем один элемент из начала буфера:

![image](https://github.com/PopekaDS/CircularBuffer/assets/70101127/bfff2118-58d0-44d1-b716-aa3abb5a33fd)

Затем снова удалим два элемента, но из конца буфера:

![image](https://github.com/PopekaDS/CircularBuffer/assets/70101127/0968f4b8-c902-4163-86d2-c6f3d1349787)

Если в буфере находится 8 элементов, то он заполнен:

![image](https://github.com/PopekaDS/CircularBuffer/assets/70101127/703aa4f8-e7e6-400f-a174-3c3d80521125)

Если продолжить запись в буфер, не принимая во внимание его заполненность, то новые данные начнут перезаписывать старые данные. В нашем случае, если добавляем элементы в конец, то перезапишутся элементы из головы:

![image](https://github.com/PopekaDS/CircularBuffer/assets/70101127/41e0fec3-ffd5-40a9-890e-9f33ce173de9)

Добавляя элементы в начало, перезапишутся элементы с конца:

![image](https://github.com/PopekaDS/CircularBuffer/assets/70101127/a96db85a-ca5b-4bfb-ad4a-2a7c03685321)

В итоге получается следующее:

![image](https://github.com/PopekaDS/CircularBuffer/assets/70101127/e1e29d55-1ee3-4cc8-954b-8bd9d623f16a)

