pyg = 'ay'

original = raw_input('Enter a word:')

if len(original) > 0 and original.isalpha():
	print original
	word = original.lower()
	first = word[0]
	if first in ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']:
		print "vowel"
		new_word = word + pyg
		print new_word
	else:
		print "consonant"
		new_word = word[1:] + first + pyg
		print new_word
else:
	print 'empty'
