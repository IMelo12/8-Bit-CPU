def convert_to_hex():
    with open("decodeROM.txt","r+") as file:
        for i in range(15):
            for j in range(8):
                element = bytes(file.readline())
                element = hex(element)
convert_to_hex()

