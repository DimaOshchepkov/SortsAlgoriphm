import matplotlib.pyplot as plt
import pandas as pd

# Список файлов с данными
files = [
    'bubble_swap.txt',
    'insertion_swap.txt',
    'tim_swap.txt'
]

# Создаем фигуру и оси
plt.figure(figsize=(10, 6))
plt.title('Зависимость количества swap операций от размера массива', fontsize=16)
plt.xlabel('Размерность массива')
plt.ylabel('Количество swap операций')

# Итерируемся по файлам
for file in files:
    # Извлекаем имя алгоритма из названия файла
    algorithm = file.split('_')[0]

    # Читаем данные из файла
    with open(file, 'r') as f:
        data = [list(map(int, line.split())) for line in f]

    # Создаем DataFrame из данных
    df = pd.DataFrame(data, columns=['Размер', 'Swap'])

    # Строим график
    plt.plot(df['Размер'], df['Swap'], label=algorithm)

plt.legend()
plt.tight_layout()
plt.show()