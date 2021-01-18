from selenium import webdriver
from BeautifulSoup import BeautifulSoup
import pandas as pd

rank=[] #List to store rank
guild=[] #List to store guilds names
points=[] #List to store points
driver.get("<a href="https://localhackday.mlh.io/build/"> https://localhackday.mlh.io/build/ </a>Leaderboard")

content = driver.page_source
soup = BeautifulSoup(content)
for a in soup.findAll('a',href=True, attrs={'class':'leader-board'}):
rank=a.find('div', attrs={'class':'leader-board'})
guild=a.find('div', attrs={'class':'leader-board'})
points=a.find('div', attrs={'class':'leader-board'})
rank.append(rank.text)
guild.append(guild.text)
points.append(points.text) 

df = pd.DataFrame({'Rank':rank,'Guild':guild,'Points':points}) 
df.to_csv('rank.csv', index=False, encoding='utf-8')

