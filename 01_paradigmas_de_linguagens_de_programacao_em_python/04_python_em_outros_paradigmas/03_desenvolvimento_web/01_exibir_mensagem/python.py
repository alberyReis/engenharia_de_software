from flask import Flask

app = Flask(__name__)

@app.route('/')
def cumprimento():
  boas_vindas = '<h1>Olá, programadores!</h1>'
  link = '<p><a href="user/usuario">Clique Aqui!</a></p>'
  return boas_vindas + link

@app.route('/user/')
@app.route('/user/<nome>')
def user(nome = 'usuario'):
  personalizar = f'<h1>Olá, {nome}!</h1>'
  instrucao = '<p>Altere o nome no <em> endereço do browser</em> \ e recarregue a página.</p>'
  return personalizar + instrucao

if __name__ == '__main__':
  app.run(debug = True)