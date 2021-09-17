
data = '''
This is a data string in the test module.
'''

def get_data(ntimes=1):
    if(not isinstance(ntimes, int)):
        raise TypeError("ntimes must be int but is " + str(type(ntimes)))
    return data*ntimes

