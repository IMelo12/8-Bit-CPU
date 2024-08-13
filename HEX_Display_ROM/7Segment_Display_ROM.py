
def ones_place_hex() -> None:
    with open("Ones_place_hex.txt","w") as file:
        string = {0:"01",1:"4f",2:"12",3:"06",4:"4c",5:"24",6:"20",7:"0f",8:"00",9:"04"}
        counter_u = 0
        counter = 0
        counter_neg = 0
        # 0 - 255 
        for i in range (0,256,1):
            if counter_u == 8:
                file.write("\n")
                counter_u = 0
            num = i % 10
            file.write(string[num] + " ")
            counter_u += 1
        file.write("\n")
        # 0 - -128
        for i in range(0,-128,-1):
            if counter_neg == 8:
                file.write("\n")
                counter_neg = 0
            num = abs(i) % 10
            file.write(string[num] + " ")
            counter_neg += 1
        file.write('\n')
        # 128 - 0
        for i in range(128,0,-1):
            if counter == 8:
                file.write("\n")
                counter = 0
            num = abs(i) % 10
            file.write(string[num] + " ")
            counter += 1
        
def tens_place_hex() -> None:
    with open("Tens_place_hex.txt", "w") as file:
        string = {0:"01",1:"4f",2:"12",3:"06",4:"4c",5:"24",6:"20",7:"0f",8:"00",9:"04"}
        counter = 0
        counter_neg = 0
        counter_s = 0

        for i in range(0,256,1):
            if counter == 8:
                file.write("\n")
                counter = 0
            num = (i//10) % 10
            file.write(string[num] + " ")
            counter += 1
        file.write("\n")
        for i in range(0,-128,-1):
            if counter_neg == 8:
                file.write("\n")
                counter_neg = 0

            num = (abs(i)//10) % 10
            file.write(string[num] + " ")
            counter_neg += 1
        file.write('\n')
        for i in range(128,0,-1):
            if counter_s == 8:
                file.write("\n")
                counter_s = 0

            num = (abs(i)//10) % 10
            file.write(string[num] + " ")
            counter_s += 1
def hundreds_place_hex() -> None:
    with open("Hundreds_place_hex.txt", "w") as file:
        string = {0:"01",1:"4f",2:"12",3:"06",4:"4c",5:"24",6:"20",7:"0f",8:"00",9:"04"}
        counter = 0
        counter_neg = 0
        counter_s = 0

        for i in range(0,256,1):
            if counter == 8:
                file.write("\n")
                counter = 0
            num = i // 100
            file.write(string[num] + " ")
            counter += 1
        file.write("\n")
        for i in range(0,-128,-1):
            if counter_neg == 8:
                file.write("\n")
                counter_neg = 0

            num = abs(i) // 100
            file.write(string[num] + " ")
            counter_neg += 1
        file.write('\n')
        for i in range(128,0,-1):
            if counter_s == 8:
                file.write("\n")
                counter_s = 0

            num = abs(i) // 100 
            file.write(string[num] + " ")
            counter_s += 1

hundreds_place_hex()
def signs_place_hex() -> None:
    with open("Signs_place_hex.txt", "w") as file:
        string = {0:"01",1:"4f",2:"12",3:"06",4:"4c",5:"24",6:"20",7:"0f",8:"00",9:"04"}
        counter = 0
        counter_s = 0

        for i in range(0,256,1):
            if counter == 8:
                file.write("\n")
                counter = 0
            file.write("7f" + " ")
            counter += 1
        file.write("\n")
        for i in range(-128,128):
            if counter_s == 8:
                file.write("\n")
                counter_s = 0
            if i < 0:
                file.write("7f ")
                counter_s += 1
            else:
                file.write("7e ")
                counter_s += 1
