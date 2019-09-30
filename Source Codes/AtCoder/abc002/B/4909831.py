str_ = input()
table = str_.maketrans({
"a":"",
"i":"",
"u":"",
"e":"",
"o":"",
})
print(str_.translate(table))