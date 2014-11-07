#include "cocos2d.h"
#include "SweepMain.h"
#include "time.h"
#include "string.h"
#include "ctime"

USING_NS_CC;

Sweep sweep[9][9];
int markNumber = 0,clickNumber = 0;

bool SweepMain::init()
{
	  if ( !Layer::init() )
     {
			return false;
     }
	  sweepSurplusTTF = CCLabelTTF::create();//剩余雷数显示

	  creatSweepMap(); //数字信息生成
	  creatSweepSprite(); //图像信息生成
	  this->setTouchEnabled(true);
	  sweepTouchCreate();//生成按钮
	  schedule(schedule_selector(SweepMain::sweepUpdate), 0.017f);//UPDATE

}

void SweepMain::sweepUpdate(float t)
{
	if ((clickNumber == 72)||(markNumber == 9))	toGameOver();	
}

void SweepMain::creatSweepMap()
{
	int numSweep = 0;
	for (int i=0;i<9;i++)
		for (int j=0;j<9;j++)
		{
			sweep[i][j].sweepNumber = 0;
			sweep[i][j].Xpoint = i;
			sweep[i][j].Ypoint = j;
			sweep[i][j].isClick = false;
		}

	std::srand(time(NULL));
	while (numSweep != 10)
	{
		int xPoint = rand()%9;
		int yPoint = rand()%9;
		if (sweep[xPoint][yPoint].sweepNumber == 0)
		{
			sweep[xPoint][yPoint].sweepNumber = 10;
			numSweep++;
		}
	}

	for (int i=0;i<9;i++)
		for (int j=0;j<9;j++)
			getSweepNumber(i,j);
}

void SweepMain::creatSweepSprite()
{
	std::string clickNumber;
	for (int i=0;i<9;i++)
		for (int j=0;j<9;j++)
		{
			sweep[i][j].sweepButton = CCSprite::create("sweep.png");
			sweep[i][j].sweepButton->setPosition(ccp(29+i*20,220-(j*20)));
			this->addChild(sweep[i][j].sweepButton);
		}
}

void SweepMain::getSweepNumber(int x,int y)
{
	if ((sweep[x-1][y-1].sweepNumber == 10)&&(x-1>=0)&&(y-1>=0)) sweep[x][y].sweepNumber++;
	if ((sweep[x-1][y+1].sweepNumber == 10)&&(x-1>=0)&&(y+1<=8)) sweep[x][y].sweepNumber++;
	if ((sweep[x+1][y-1].sweepNumber == 10)&&(x+1<=8)&&(y-1>=0)) sweep[x][y].sweepNumber++;
	if ((sweep[x+1][y+1].sweepNumber == 10)&&(x+1<=8)&&(y+8<=8)) sweep[x][y].sweepNumber++;
	if ((sweep[x][y-1].sweepNumber == 10)&&(y-1>=0)) sweep[x][y].sweepNumber++;
	if ((sweep[x-1][y].sweepNumber == 10)&&(x-1>=0)) sweep[x][y].sweepNumber++;
	if ((sweep[x][y+1].sweepNumber == 10)&&(y+1<=8)) sweep[x][y].sweepNumber++;
	if ((sweep[x+1][y].sweepNumber == 10)&&(x+1<=8)) sweep[x][y].sweepNumber++;
}

void SweepMain::sweepTouchCreate()
{
	Listener = EventListenerTouchOneByOne::create();   
	Listener->setSwallowTouches(true);

	
	Listener->onTouchBegan = [](Touch* touch, Event* event)
	{

		 CCPoint touchPoint = touch->getLocationInView();     
		 touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint );  
		 for (int i=0;i<9;i++)
			 for (int j=0;j<9;j++)
			 {
					CCRect rc1 = sweep[i][j].sweepButton->boundingBox(); 

					if(rc1.containsPoint(touchPoint))
					{
						sweep[i][j].sweepButton->setTexture("sweep0.png");
					}
			 }
         return true;
	};

	Listener->onTouchMoved = [](Touch* touch, Event* event)
	{

		 CCPoint touchPoint = touch->getLocationInView();     
		 touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint );  
		 for (int i=0;i<9;i++)
			 for (int j=0;j<9;j++)
			 {
					CCRect rc1 = sweep[i][j].sweepButton->boundingBox(); 

					if(rc1.containsPoint(touchPoint))
					{
						sweep[i][j].sweepButton->setTexture("sweep0.png");
						clock_t touchTime = clock();
						while (clock()-touchTime < CLOCKS_PER_SEC*2){};
						sweep[i][j].markSweepButton();
					}
			 }

        
	};
    Listener->onTouchEnded = [=](Touch* touch, Event* event)
	{
		 CCPoint touchPoint = touch->getLocationInView();     
		 touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint );  
		 for (int i=0;i<9;i++)
			 for (int j=0;j<9;j++)
			 {
					CCRect rc1 = sweep[i][j].sweepButton->boundingBox(); 

					if(rc1.containsPoint(touchPoint))
					{
						sweep[i][j].clickSweepButton();	
					}
			 }
        
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(Listener, sweep[0][0].sweepButton);
}

void Sweep::clickSweepButton()
{
	if (!this->isClick)
	{
		std::string spriteName;
		spriteName = "sweep"+(char)(sweep[this->Xpoint][this->Ypoint].sweepButton+48);
		spriteName = spriteName+".png";
		sweep[this->Xpoint][this->Ypoint].sweepButton->setTexture(spriteName);
		
		if (this->sweepNumber == 10) toGameOver();

		if (this->sweepNumber == 0)
		{
			sweep[this->Xpoint + 1][this->Ypoint + 1].clickSweepButton();
			sweep[this->Xpoint - 1][this->Ypoint + 1].clickSweepButton();
			sweep[this->Xpoint + 1][this->Ypoint - 1].clickSweepButton();
			sweep[this->Xpoint - 1][this->Ypoint - 1].clickSweepButton();
			sweep[this->Xpoint + 1][this->Ypoint].clickSweepButton();
			sweep[this->Xpoint - 1][this->Ypoint].clickSweepButton();
			sweep[this->Xpoint][this->Ypoint + 1].clickSweepButton();
			sweep[this->Xpoint][this->Ypoint - 1].clickSweepButton();   //递归
		}
		this->isClick = true;
		clickNumber++;
	}
}

void Sweep::markSweepButton()
{
	if (!this->isClick)
	{
		this->isClick = true;
		markNumber++;
		sweep[this->Xpoint][this->Ypoint].sweepButton->setTexture("sweep_mark.png");
		if (sweep[this->Xpoint][this->Ypoint].sweepNumber != 10) toGameOver();
	}
}

void SweepMain::toGameOver()
{

}


CCScene* SweepMain::gameScene()
{
	CCScene* playScene = CCScene::create();
	SweepMain* layer = SweepMain::create();

	playScene->addChild(layer);
	return playScene;
}
