class NomeCompleto:
  def __init__(self, nome, sobrenome):
    self.nome = nome
    self.sobrenome = sobrenome
  @classmethod
  def fromString(cls, texto):
    nome, sobrenome = map(str, texto.split(' '))
    objeto = cls(nome, sobrenome)
    return objeto

registro1 = NomeCompleto.fromString('Luiz Braga')
print(registro1.nome, registro1.sobrenome)