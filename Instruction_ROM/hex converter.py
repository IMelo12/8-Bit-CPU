def convert_to_hex():
    with open("decodeROM.txt","r") as file:
        for i in range(15):
            for j in range(8):
                element = file.readline()
                
