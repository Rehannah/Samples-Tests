from selenium import webdriver
import yaml

conf = yaml.load(open('loginDetails.yml'))
myMoodleuser = conf['moodle_user']['username']
myMoodlepassword = conf['moodle_user']['password']


driver = webdriver.Chrome()

def login(url,usernameId, username, passwordId, password, submit_buttonId):
   driver.get(url)
   driver.find_element_by_id(usernameId).send_keys(username)
   driver.find_element_by_id(passwordId).send_keys(password)
   driver.find_element_by_id(submit_buttonId).click()
login("https://myelearning.sta.uwi.edu/login/index.php/", "username", myMoodleuser, "yui_3_17_2_1_1610939283938_29", myMoodlepassword "loginbtn")















