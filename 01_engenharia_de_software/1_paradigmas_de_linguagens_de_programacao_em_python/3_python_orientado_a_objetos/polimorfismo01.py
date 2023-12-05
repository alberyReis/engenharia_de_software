class Argentina():
  def capital(self):
    print('Buenos Aires é a capital da Argentina.')
  def lingua_oficial(self):
    print('O espanhol é a lingua oficial da Argentina.')

class Brasil():
  def capital(self):
    print('Brasília é a capital do Brasil.')
  def lingua_oficial(self):
    print('O português é a lingua oficial do Brasil.')

obj_arg = Argentina()
obj_bra = Brasil()

for pais in (obj_arg, obj_bra):
  pais.capital()
  pais.lingua_oficial()


