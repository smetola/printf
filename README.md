# ft_printf

**ft_printf** es una reimplementación de la función estándar `printf()` de C. Este proyecto me ha permitido entender en profundidad cómo funciona internamente esta función y cómo manejar **argumentos variádicos** en C.

## ¿Qué hace ft_printf?

La función `ft_printf()` es capaz de gestionar diferentes tipos de conversiones, imitando el comportamiento de la función original:

- `%c` – Imprime un solo carácter.
- `%s` – Imprime una cadena de texto.
- `%p` – Imprime un puntero en formato hexadecimal.
- `%d`/`%i` – Imprime un número decimal (base 10).
- `%u` – Imprime un número decimal sin signo.
- `%x`/`%X` – Imprime un número hexadecimal (base 16).
- `%%` – Imprime el símbolo de porcentaje.

## ¿Qué he aprendido?

Con **ft_printf**, he profundizado en:

- **Funciones variádicas**: Cómo trabajar con un número variable de argumentos usando `va_list`.
- **Manipulación de formatos**: Interpretar y manejar especificadores de formato.
- **Optimización del código**: Balancear la eficiencia con la legibilidad al implementar conversiones complejas.
