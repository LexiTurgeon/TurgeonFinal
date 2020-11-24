listofNumbers = [5, 1, 4, 8, 12, 7, 4, 9, 11, 14, 32, 2, 7, 12]

evenNumbers = []
oddNumbers = [] 

for x in listofNumbers: 
	if x % 2 == 0: 
		evenNumbers.append(x) 
	else: 
		oddNumbers.append(x) 

print("The Even Numbers are: ")
print(str(evenNumbers)) 
print("The Odd Numbers are:  ")
print(str(oddNumbers))
