from PIL import Image
from sys import argv

im = Image.open('./../data/' + argv[1] + '.png')
# im = Image.open("./../data/simple.png")

pix = im.load()
width, height = im.size

raw = list()
for y in range(height):
    row = list()
    for x in range(width):
        row.append(str(pix[x,y]))
    row.append('\n')
    raw.append(''.join(row))

out = ''.join(raw)

# with open(".\\..\\data\\simple.txt", "w+") as file:
with open('.\\..\\data\\' + argv[1] + '.txt', 'w+') as file:
    file.write(out)