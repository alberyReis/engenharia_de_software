# Imutabilidade
def sum(numeros):
  if not numeros:
    return 0
  primeiro = numeros[0]
  resto = numeros[1:]
  return primeiro + sum(resto)

print(sum([2, 4, 6, 8, 10]))

print('\nSegundo exemplo')
lista = ['Ferrari']
nova_lista = lista + ['porsche']
print(nova_lista)

print('\nTerceiro exemplo')
import operator
print(operator.add(10, 20))

print('\nQuarto exemplo')
from functools import reduce
print(reduce(operator.add, [10, 20]))
print(reduce(operator.concat,['Aprendendo reduce!']))