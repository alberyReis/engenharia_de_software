import datetime

class Conta:
  def __init__(self, clientes, numero, saldo):
    self.clientes = clientes
    self.numero = numero
    self.saldo = saldo
    self.extrato = Extrato()
  def depositar(self, valor):
    self.saldo += valor
    self.extrato.transacoes.append(['DEPOSITO', valor])
  def sacar(self, valor):
    if self.saldo < valor:
      return False
    else:
      self.saldo -= valor
      self.extrato.transacoes.append(['SAQUE', valor])
      return True

class Cliente: 
  def __init__(self, cpf, nome, endereco):
    self.cpf = cpf
    self.nome = nome
    self.endereco = endereco

class Extrato:
  def __init__(self):
    self.transacoes = []
  def imprimir(self):
    for p in self.transacoes:
      print(p[0], p[1])

class ContaEspecial(Conta):
  def __init__(self, clientes, numero, saldo, limite):
    Conta.__init__(self, clientes, numero, saldo)
    self.limite = limite
  def sacar(self, valor):
    if(self.saldo + self.limite) < valor:
      return False
    else:
      self.saldo -= valor
      self.extrato.transacoes.append(['SAQUE', valor])
      return True

class Poupanca:
  def __init__(self, taxaremuneracao):
    self.taxaremuneracao = taxaremuneracao
    self.data_abertura = datetime.datetime.today()
  def remuneraConta(self):
    self.saldo += self.saldo * self.taxaremuneracao

class ContaRemuneradaPoupanca(Conta, Poupanca):
  def __init__(self, clientes, numero, saldo, taxaremuneracao):
    Conta.__init__(self, clientes, numero, saldo)
    Poupanca.__init__(self, taxaremuneracao)
  def remuneraConta(self):
    self.saldo += self.saldo * self.taxaremuneracao / 30

class ContaCliente:
  def __init__(self, numero, IOF, IR, valorinvestido, texarendimento):
    self.numero = numero
    self.IOF = IOF
    self.IR = IR
    self.valorinvestido = valorinvestido
    self.taxarendimento = taxarendimento
  def CalculoRendimento(self):
    pass

class ContaComum(ContaCliente):
  def __init__(self, numero, IOF, IR, valorinvestido, taxarendimento):
    super().__init__(numero, IOF, IR, valorinvestido, taxarendimento)
  def CalculoRendimento(self):
    self.valorinvestido += self.valorinvestido * self.taxarendimento

class ContaRemunerada(ContaCliente):
  def __init__(self, numero, IOF, IR, valorinvestido, taxarendimento):
    super().__init__(self, numero, IOF, IR, valorinvestido, taxarendimento)
  def CalculoRendimento(self):
    self.valorinvestido += self.valorinvestido * self.taxarendimento
    self.valorinvestido += self.valorinvestido * self.IOF

class ExcecaoCustomizada(Exception):
  pass
x = -1
if x < 0:
  raise Exception('Valor negativo!!!')
x = 'Hello'
if not type(x) is int:
  raise TypeError('Use apenas inteiros')

try:
  print(c1)
except:
  print('Existe um problema')

c1 = Cliente('111111111-11', 'Ana', 'Rua das Marrecas')
c2 = Cliente('222222222-22', 'Carlos', 'Rua dos Gansos')
conta = Conta([c1, c2], 24237891, 2500.00)

conta.depositar(1000)
conta.sacar(500)
conta.extrato.imprimir()

cx = ContaRemuneradaPoupanca([c1, c2], 98939123, 1500.00, 0.03)
cx.remuneraConta()
print(cx.saldo)

try:
  print(c1.nome)
except:
  print('Existe um problema')