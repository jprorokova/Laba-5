# Laba-5
Лабораторная работа 5 по ОП
Варіант #1. Пошук найближчих установ до заданої географічної точки.
Написати програму, що за вказаними координатами та радіусом виводить список всіх установи, що знаходять всередині кола/квадрата із центром у заданих координатах та заданим радіусом.

Майже будь-якій програмі (застосунку, сервісу) сьогодні доводиться мати справу з даними. Сервіси зберігають інформацію про своїх користувачів (ім'я\логін), їх дії (замовлення, особисті кабінети), купу аналітичних даних (що клікнув користувач, як довго знаходився на певній сторінці, як часто заходить у сервіс). Цих даних накопичується так багато, що обробляти та аналізувати їх вручну стає дуже важко. Виникла ціла галузь комп'ютерних наук - Data Science, термін Bid Data та багато чого іншого цікавого, з чим ви ще обов'язково познайомитесь далі.

В цій же роботі вам пропонується більш просте завдання — написати структуру для ефективної обробки певних даних. Очевидно, що якщо зберігати дані (скажімо, інформацію про користувачів) невпорядковано, то навіть при порівняно невеликій базі в мільйон записів кожна операція — спроба щось знайти буде потребувати повного перебору абсолютно всіх записів, що буде займати багато ресурсів — як процесорних, так і часових.

Будь-яка сучасна база даних підтримує індексування — створення допоміжної структури даних, що дозволяє набагато швидше виконувати певні дії над даними. Наприклад, якщо побудувати навіть найпростіше бінарне дерево пошуку, то запит "знайти користувача віком 32 роки" буде виконуватись вже за логарифмічний час. Префіксне дерево в свою чергу дозволить виконувати подібні запити на полях що є рядками (наприклад, ім'я). Сьогодні в базах даних дуже часто біля одного набору даних знаходиться декілька індексів,що дозволяють робити ефективні запити на різних полях.

Індекси можна будувати не тільки над рядками та числами, але й над більш цікавими даними - наприклад над географічними точками. Для цього є навіть окрема назва — Spatial index. Найчастіше, такий індекс реалізовується за допомогою спеціальних дерев, що називаються R-Tree

Вхідні та вихідні дані
Вам дається файл наступного формату (csv) лінк

Широта; Довгота; Тип; Підтип; Назва; Адреса;
Ці дані взяті з відкритих джерел — із Open Street Map. Для вашої зручності дані були попередньо оброблені у такий зручний формат із оригінального формату .osm. Ваше завдання - написати програму, що буде приймати на вході географічну точку (широта, довгота), ціле число N, та тип/підтип шуканого об'єкта. Програма має вивести на екран всі установи, що потрапляють у квадрат довжиною N кілометрів із центром в заданій точці. Очевидний варіант — перебирати всі точки та перевіряти, чи потрапляє вона в потрібний сектор. Але це дуже неефективно, і суть завдання полягає саме у роботі зі структурою даних.


Також пам'ятайте, що координати певної точки на планеті - це широта та довгота, при чому відстань у один градус між двома точками на екваторі набагато більше, ніж відстань у один градус близько до полюсів. Це треба враховувати і коректно рахувати відстані. Для кращого розуміння потрібно почитати про Проекцію Меркатора та пограти у відому гру від Гугла, що показує як ця проекція викривлює справжні масштаби
