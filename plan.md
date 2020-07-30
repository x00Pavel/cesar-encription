# План

1) Флаги компилятора
   * Флаги используются для изменения работы компилятора
   * Помогают отслеживать ошибки при разработке 
2) Заголовочные файлы
   * Использовать "header"
   * Должно быть два файлы: .h .c
   * gcc header.c main.c -o main
3) Makefile
   * Используется для упрощения сборки проектов
   * Формат
4) Функция для вычисления факториала рекурсивно
```
int main(){
    int res = fact(10);
    printf("%d\n", res);
}

int fact(int n){
    if (n == 0){
        return 1;
    }
    return n * fact(n-1);
}
```
5) Знакомство с массивами
    * ```char mas[10];```
    * ```int mas[] = {0, 1, 2}```
6) [Указатели](https://www.programiz.com/c-programming/c-pointers)
    * Порисовать, показать что это такое
    * Напоминалка на бумажке
    ```
    // что выдаст?
    int* pc, c;
    c = 5;
    pc = &c;
    c = 1;
    printf("%d", c);    // Output: 1
    printf("%d", *pc);  // Ouptut: 1
    ```
    **Про ошибки!**

7) [Массив + указатель](https://www.programiz.com/c-programming/c-pointers-arrays)
   1) Поменять два числа местами
    ```
    #include <stdio.h>
    void swap(int *n1, int *n2);

    int main()
    {
        int num1 = 5, num2 = 10;

        // address of num1 and num2 is passed
        swap( &num1, &num2);

        printf("num1 = %d\n", num1);
        printf("num2 = %d", num2);
        return 0;
    }

    void swap(int* n1, int* n2)
    {
        int temp;
        temp = *n1;
        *n1 = *n2;
        *n2 = temp;
    }
    ``` 
    1) Поинтрова арифметика <- Посчитать среднее арифмитиеческое
    2) Знакомство с алокацие памяти + указатели
        ```
        #include <stdio.h>
        int main()
        {
            int i, n, sum = 0, average;

            printf("Enter number of elements: ");
            scanf("%d", &n);

            int *marks = (int *)malloc(n * sizeof(int)); // !!!
            for(i=0; i<n; ++i)
            {
                printf("Enter number%d: ",i+1);
                scanf("%d", &marks[i]);
                
                // adding integers entered by the user to the sum variable
                sum += marks[i];
            }

            average = sum/n;
            printf("Average = %d", average);
            free(marks)
            return 0;
        }

8) [Работа со строками](https://www.programiz.com/c-programming/c-strings)
9)  [Macros](https://www.programiz.com/c-programming/c-preprocessor-macros) 