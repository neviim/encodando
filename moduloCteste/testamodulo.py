import moduloteste

print " "
print dir(moduloteste)

param1 = 1
param2 = 3
param3 = 'teste'

# chama funcao em C de soma
print " "
try:
	print 'Valor de ' + str(param1) +' + ' \
					  + str(param2) + ': ' \
					  + str(moduloteste.soma(param1, param2))

except moduloteste.erro as e:
	print 'erro na lib: ' + str(e)

# chama funcao em C de duplicastring
print " "
try:
	print 'String ' +param3+ ' duplicada' +': '+ moduloteste.duplicastring(param3)
	print " "

except moduloteste.erro as e:
	print 'erro na lib: ' + str(e)
	print " "
