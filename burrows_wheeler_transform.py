"""
Burrows–Wheeler Transform (BWT aka block-sorting compression)
This transformation algorithm basically permutes the order of input string. It works very well with strings containing
repeating characters. This algorithm is used in other algorithms for sequence alignment, image compression, data
compression, etc.
"""

def bwt_encrypt(cleartext, anchor='$'):
	"""
	Encrypts the `cleartext` string following BWT encryption algorithm.

	If the argument `anchor` isn't passed in, the default character '$' is used.

	Parameters
	==========
	cleartext : str
		The string to be encrypted.
	anchor : str
		The character that will help to decrypt the ciphertext (default is '$').
		This character must be unique to the string, otherwise the algorithm MAY fail.

	Raises
	======
	TypeError
		If the argument `anchor` isn't passed in as a string.
	ValueError
		If the length of `anchor` parameter is not equal to 1
		or,
		if the length of `cleartext` parameter is equal to 0.
	"""

	if type(anchor) != str:
		raise TypeError("The anchor cannot be anything other than string.")
	elif len(anchor) < 1:
		raise ValueError("The anchor cannot be nothing.")
	elif len(anchor) > 1:
		raise ValueError("The anchor cannot be multiple characters.")
	elif len(cleartext) == 0:
		raise ValueError("Please enter a valid sequence of strings to encrypt.")

	cleartext += anchor
	all_rotations = []

	for letter in cleartext:
		all_rotations.append(cleartext)
		cleartext = cleartext[1:] + letter

	all_rotations.sort()
	ciphertext = ''

	for rotation in all_rotations:
		ciphertext += rotation[-1]

	return ciphertext


def bwt_decrypt(ciphertext, anchor='$'):
	"""Decrypts the `ciphertext` string following BWT decryption algorithm.

	If the argument `anchor` isn't passed in, the default character '$' is used.

	Parameters
	==========
	ciphertext : str
		The string to be decrypted.
	anchor : str
		The character that was set as `anchor` during encryption.

	Raises
	======
	TypeError
		If the argument `anchor` isn't passed in as a string.
	ValueError
		If the length of `anchor` parameter is not equal to 1
		or,
		if a valid `ciphertext` parameter is not passed.
	"""

	if type(anchor) != str:
		raise TypeError("The anchor cannot be anything other than string.")
	elif len(anchor) < 1:
		raise ValueError("The anchor cannot be nothing.")
	elif len(anchor) > 1:
		raise ValueError("The anchor cannot be multiple characters.")
	elif len(ciphertext.replace(anchor, '')) == 0:
		raise ValueError("Please enter a valid sequence of strings to decrypt.")

	ciphertext = list(ciphertext)
	all_rotations = list(ciphertext)

	for i in range(len(ciphertext) - 1):
		all_rotations.sort()
		for j in range(len(ciphertext)):
			all_rotations[j] = ciphertext[j] + all_rotations[j]
			if all_rotations[j][0] == anchor and len(all_rotations[j]) == len(ciphertext):
				return all_rotations[j][1:]
