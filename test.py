# coding:utf-8
class Teacher():
    def __init__(self, name):
        self.__name = name

    def get_name(self):
        return self.__name

b = Teacher(55)
print b.get_name()