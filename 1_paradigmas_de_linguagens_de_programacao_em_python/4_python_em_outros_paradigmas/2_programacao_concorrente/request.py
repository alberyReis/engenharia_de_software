import threading
import urllib.request
import time

start = time.time()

urls = ["http://www.google.com", "http://www.apple.com", "http://www.microsoft.com", "http://www.instagram.com"]

def chama_url(url):
  req = urllib.request.Request(url)
  response = urllib.request.urlopen(req)
  the_page = response.read()
  print("'%s\' carregado em %ss" % (url, (time.time() - start)))

threads = [threading.Thread(target = chama_url, args = (url,)) for url in urls]

for thread in threads:
  thread.start()
for thread in threads:
  thread.join()

print("Elapsed Time: %s" % (time.time() - start))
