class Veiculo:
  def __init__(self, nome, velocidade_max, quilometro_litro):
    self.nome = nome
    self.velocidade_max = velocidade_max
    self.quilometro_litro = quilometro_litro
  def capacidade_assentos(self, capacidade):
    print(f'A capacidade máxima de assentos do veículo {self.nome} é {capacidade}')
  def toStr(self):
    print(f'nome = {self.nome}')
    print(f'velocidade_max = {self.velocidade_max}')
    print(f'Quilômetros pecorridos por litro = {self.quilometro_litro}')

class Onibus(Veiculo):
  def capacidade_assentos(self, capacidade = 70):
    return super().capacidade_assentos(capacidade = 70)

modelo_carro = Veiculo('Fusca', 180, 10)
modelo_carro.toStr()

onibus_escolar = Onibus('Scania', 120, 8)
onibus_escolar.toStr()
onibus_escolar.capacidade_assentos()