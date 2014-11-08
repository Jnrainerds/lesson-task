import sys

class eatNuts:
    """This class retain one kind of nuts which can be removed to eat
    in an individually way,and will raise an error
    if you didn't choose the right nuts.
    """

    def __init__(self, items={}):
        """
        through the initial dictionary of items
        """
        if type(items) != type({}):
                raise TypeError("Nuts requires a dictionary but was given %s" %(type(items)))
        self.items = items
        return

    def has(self, nuts_name, quantity = 1):
        """
        has(nuts_name, quantity) - checks if the string nuts_name is existence.
        Quantity defaults to 1. Returns True if nuts_name exists, Faulse otherwise.
        """
        return self.has_various({nuts_name:quantity})

    def has_various(self, nuts):
        """
        has_various(nuts) determines if the dictionary nuts_name has enough to offer.
        returns True if there's enough, False if there's not or if an element does not exist.
        """
        try:
            for keys in nuts.keys():
                if self.items[keys] < nuts[keys]:
                    return False
            return True
        except KeyError:
            return False


    def __get_multi(self, nuts_name, quantity):
        """
        __get_multi(nuts_name, quantity) - removes more than one of a nuts item.
        Returns the number of items removed, returns False if there isn't enough nuts_name in the fidge. This should only be used internally, after the type cheking has been done
        """
        try:
            if (self.items[nuts_name] is None):
                return False;
            if (quantity > self.items[nuts_name]):
                return False;
            self.items[nuts_name] = self.items[nuts_name] - quantity
        except KeyError:
            return False
        return quantity

    def get_one(self, nuts_name):
        """
        get_one(nuts_name) - get one nut to eat:
        1 as a result, or False if there wasn't enough.
        """
        if type(nuts_name) != type(""):
            raise TypeError("get_one requirs a string, given a %s" %(type(food_name)))
        else:
            result = self.__get_multi(nuts_name, 1)
        return result
    
    def get_many(self, nuts_dict):
        """
        get_mant(nuts_dict) - takes out a whole dictionary worth of food.
        returns a dictonary with all of the nuts.
        Return False if there are not enough nuts or if a dictionary isn't provided.
        """
        if self.has_various(nuts_dict):
            nuts_removed = {}
            for item in nuts_dict.keys():
                nuts_removed[item] = self.__get_multi(item, nuts_dict[item])
        return nuts_removed[item]

    def eatOneNut(self, nuts_name):
        num = self.get_one(nuts_name)
        while(num > 0):
            print("There is only one %s I have to eat it now:)" %(nuts_name))
            num = num - 1
        else:
            print("There is no more nuts, focus on your work!")

    def eatSomeNuts(self, nuts_dict):
        num = self.get_many(nuts_dict)
        while(num > 0):
            print("I'm hungry, let me eat some nuts")
            value = value - 1
        else:
            print("You have ate all nuts, don't forget your plan!")
        

    
    
