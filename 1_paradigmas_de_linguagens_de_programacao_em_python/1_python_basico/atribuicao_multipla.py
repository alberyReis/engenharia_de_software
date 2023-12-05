a, b = 1, 2

print('Antes da troca')
print(f'O valor da variáveis: a = {a}, b = {b}')

temp = a
a = b
b = temp

print('Primeira troca')
print(f'O valor das variáveis: a = {a}, b = {b}')

a, b = b, a

print('Segunda troca')
print(f'Ovalor das variáveis: a = {a}, b = {b}')