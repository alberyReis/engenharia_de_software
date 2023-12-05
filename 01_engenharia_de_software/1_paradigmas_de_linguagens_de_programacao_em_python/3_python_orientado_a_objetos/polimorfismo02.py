class Veiculo:
  def rodar(self):
    print('Reduz o consumo de combustível.')

class VeiculoEletrico(Veiculo):
  def rodar(self):
    super().rodar()
    print('Esse veículo utiliza a eletricidade.')

veiculo_eletrico = VeiculoEletrico()
veiculo_eletrico.rodar()