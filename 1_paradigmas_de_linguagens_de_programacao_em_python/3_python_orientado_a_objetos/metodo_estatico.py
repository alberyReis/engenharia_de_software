class NomeCompleto:
  def __init__(self, nome, sobrenome):
    self.nome = nome
    self.sobrenome = sobrenome

  @classmethod
  def fromString(cls, texto):
    nome, sobrenome = map(str, texto.split(' '))
    objeto = cls(nome, sobrenome)
    return objeto

  @staticmethod
  def isValid(texto):
    nomes = texto.split(' ')
    return len(nomes) > 1

print(NomeCompleto.isValid('Albery'))
