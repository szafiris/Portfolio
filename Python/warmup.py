# Python Warm Up
# Some practice coding problems in Python. Done in collaboration with Alexia Filler (github: afiller1)
import math
import random
import requests
from cryptography.fernet import Fernet


# 1
def change(number):
    if number < 0:
        raise ValueError('amount cannot be negative')
    quarters = math.floor(number / 25)
    number = number % 25
    dimes = math.floor(number / 10)
    number = number % 10
    nickels = math.floor(number / 5)
    number = number % 5
    pennies = number
    coins = (quarters, dimes, nickels, pennies)
    return coins


# 2
def strip_quotes(phrase):
    phrase = phrase.replace('"', '')
    phrase = phrase.replace('\'', '')
    return phrase


# 3
def scramble(phrase):
    str_phrase = str(phrase)
    split_phrase = list(str_phrase)
    phrase_l = len(split_phrase)
    shuffled_phrase = []
    while phrase_l > 0:
        phrase_l -= 1
        rand = random.randint(0, phrase_l)
        shuffled_phrase.append(split_phrase[rand])
        split_phrase.pop(rand)
    return "".join(shuffled_phrase)


# 4
def powers(number, limit):
    current_num = number
    count = 0
    while True:
        if current_num ** count > limit:
            return StopIteration
        yield current_num ** count
        count += 1


# 5
def triples(limit):
    answer = []
    for c in range(1, limit + 1):
        for b in range(1, c):
            for a in range(1, b):
                if a * a + b * b == c * c:
                    answer.append((a, b, c))
    return answer


# 6
def say(word=None):
    if not word:
        return ''
    return lambda next_word=None: word if(not next_word) else say(word + ' ' + next_word)


# 7
def interleave(start_array, *args):
    end_array = []
    count = 0
    min_length = min(len(start_array), len(args))
    double_min_length = min_length * 2
    max_length = max(len(start_array), len(args))
    for i in range(0, double_min_length):
        if i % 2 == 0:
            end_array.append(start_array[int(i / 2)])
        else:
            end_array.append(args[count])
            count += 1
    for k in range(min_length, max_length):
        if len(start_array) > len(args):
            end_array.append(start_array[min_length])
            double_min_length += 1
            min_length += 1
        else:
            end_array.append(args[min_length])
            double_min_length += 1
            min_length += 1
    return end_array


# 8
class Cylinder:
    """A Python Cylinder Class"""
    def __init__(self, radius=1, height=1):
        self.radius = radius
        self.height = height

    @property
    def volume(self):
        "Returns the Volume of the Cylinder"
        return math.pi * self.height * self.radius * self.radius

    @property
    def surface_area(self):
        "Returns the Surface Area of the Cylinder"
        baseArea = 2 * math.pi * self.radius * self.radius
        sideArea = 2 * math.pi * self.radius * self.height
        return baseArea + sideArea

    def stretch(self, factor=1):
        "Increases the Height by a factor"
        self.height = (self.height * factor)

    def widen(self, factor=1):
        "Increases the Radius by a factor"
        self.radius = (self.radius * factor)


# 9
def make_crypto_functions(key):

    def enc(bytesObject):
        FernetKey = Fernet(key)
        token = FernetKey.encrypt(bytesObject)
        return token

    def dec(bytesObject):
        FernetKey = Fernet(key)
        token = FernetKey.decrypt(bytesObject)
        return token
    return(enc, dec)


# 10
def random_name(**kwargs):
    params = {'gender': kwargs.get('gender'), 'region': kwargs.get('region'),
              'amount': 1}
    response = requests.get("http://api.uinames.com", params=params)
    name = response.json()
    if 'error' in name:
        raise ValueError(f'{{"error": "{name["error"]}"}}')
    firstName = name["name"]
    lastName = name["surname"]
    fullName = firstName + ", " + lastName
    return fullName
