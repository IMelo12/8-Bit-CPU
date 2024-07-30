

def ones():

    with open("ones.txt",'w') as file:
        counter = 0

        string = ["01", "4f", "12", "06", "4c", "24", "20", "0f", "00", "04"]

        for x in range (25):
            for j in range(10):
                if counter == 8:
                    file.write('\n')
                    counter = 0
                file.write(string[j])
                file.write(" ")
                counter += 1
#ones()



def tens():
    with open("tens.txt", "w") as file:
        counter = 0
        index = 0
        tens = 0

        string = ["4f", "12", "06", "4c", "24", "20", "0f", "00", "04"]

        for i in range(256):
            if i < 10 or 100<i<109 or 200<i<209:
                file.write('01 ')
                counter += 1
                if counter == 8:
                    file.write('\n')
                    counter = 0
            else:
                ptr = string[index]
                file.write(ptr + " ")
                counter += 1
                tens += 1
                if counter == 8:
                    file.write('\n')
                    counter = 0
                if tens == 10:
                    index += 1
                    tens = 0
                if index > 8:
                    index = 0
#tens()

def hundreds ():
    with open("hundreds.txt", "w") as file:
        counter = 0
        for i in range(260):
            if counter == 8:
                file.write('\n')
                counter = 0
            if 0<i<101:
                file.write('01 ')
                counter += 1
            if 102<i<211:
                file.write('4f ')
                counter += 1
            if i>= 212:
                file.write('12 ')
                counter += 1
#hundreds()


# [-128,+127]
#string = [0:"01",1: "4f",2: "12",3: "06",4: "4c",5: "24",6: "20",7: "0f",8: "00",9: "04"]


# good ----------------------------------
def sign_ones():
    with open("sign_ones.txt","w") as file:
        string = {0:"01",1:"4f",2:"12",3:"06",4:"4c",5:"24",6:"20",7:"0f",8:"00",9:"04"}
        counter = 0
        counter_neg = 0
        for i in range(0,-128,-1):
            if counter_neg == 8:
                file.write("\n")
                counter_neg = 0

            num = abs(i) % 10
            file.write(string[num] + " ")
            counter_neg += 1
        file.write('\n')
        for i in range(128,0,-1):
            if counter == 8:
                file.write("\n")
                counter = 0

            num = abs(i) % 10
            file.write(string[num] + " ")
            counter += 1
        
        
#sign_ones()

def sing_ten():
    with open("sign_ten.txt","w") as file:
        string = {0:"01",1:"4f",2:"12",3:"06",4:"4c",5:"24",6:"20",7:"0f",8:"00",9:"04"}
        counter = 0
        counter_neg = 0
        for i in range(0,-128,-1):
            if counter_neg == 8:
                file.write("\n")
                counter_neg = 0

            num = (abs(i)//10) % 10
            file.write(string[num] + " ")
            counter_neg += 1
        file.write('\n')
        for i in range(128,0,-1):
            if counter == 8:
                file.write("\n")
                counter = 0

            num = (abs(i)//10) % 10
            file.write(string[num] + " ")
            counter += 1
#sing_ten()

def sign_hunds():
    with open("sign_hunds.txt","w") as file:
        string = {0:"01",1:"4f",2:"12",3:"06",4:"4c",5:"24",6:"20",7:"0f",8:"00",9:"04"}
        counter = 0
        counter_neg = 0
        for i in range(0,-128,-1):
            if counter_neg == 8:
                file.write("\n")
                counter_neg = 0

            num = abs(i) // 100
            file.write(string[num] + " ")
            counter_neg += 1
        file.write('\n')
        for i in range(128,0,-1):
            if counte == 8:
                file.write("\n")
                counter = 0

            num = abs(i) // 100 
            file.write(string[num] + " ")
            counter += 1

#sign_hunds()

def sign_sign():
    with open("sign_sign.txt", "w") as file:
        counter = 0
        for i in range(-128,128):
            if counter == 8:
                file.write("\n")
                counter = 0
            if i < 0:
                file.write("7f ")
                counter += 1
            else:
                file.write("7e ")
                counter += 1
sign_sign()

# good --------------------------------------

#string = [0:"01",1:"4f",2:"12",3:"06",4:"4c",5:"24",6:"20",7:"0f",8:"00",9:"04"]

def signed_tens():
    with open("tens_signed.txt", "w") as file:
        counter_neg = 0
        counter_pos = 0
        string_neg = ["4f","01","04","00","0f","20","24","4c","06","12","4f","01"]
        string_pos = ["01","4f","12","06","4c","24","20","0f","00","04","01","4f"]
        
        for i in range(8):
            file.write("12"+" ")
        file.write("\n")

        for i in range(12):
            for j in range(10):
                if counter_neg == 8:
                    file.write("\n")
                    counter_neg = 0
                ptr_neg = string_neg[i]
                file.write(ptr_neg + " ")
                counter_neg += 1

        file.write("\n")

        for i in range(12):
            for j in range(10):
                if counter_pos == 8:
                    file.write("\n")
                    counter_pos = 0
                ptr_pos = string_pos[i]
                file.write(ptr_pos + " ")
                counter_pos += 1
        file.write("\n")
        for i in range(8):
            file.write("12"+ " ")
        
#signed_tens()

def signed_hundreds():
    with open("hundreds_signed.txt","w")as file:
        string = {0:"01",1:"4f",2:"12",3:"06",4:"4c",5:"24",6:"20",7:"0f",8:"00",9:"04"}
        counter = 0
        for i in range(-128,128):
            if counter == 8:
                file.write("\n")
                counter = 0
            num = abs(i) // 100
            file.write(string[num]+ " ")
            counter += 1
#signed_hundreds()
def not_sign():
    with open("not_sign.txt","w")as file:
        counter = 0
        for i in range(-128,128):
            if counter == 8:
                file.write("\n")
                counter = 0
            file.write("7f ")
            counter +=1
#not_sign()

def sign():
    with open("signs.txt", "w") as file:
        counter = 0
        for i in range(-128,128):
            if counter == 8:
                file.write("\n")
                counter = 0
            if i < 0:
                file.write("7e ")
                counter += 1
            else:
                file.write("7f ")
                counter += 1
#sign()
                


            


