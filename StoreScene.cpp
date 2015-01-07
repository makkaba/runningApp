//
//  StoreScene.cpp
//  kingdomCell
//
//  Created by chungkiwan on 2014. 2. 6..
//
//

#include "StoreScene.h"
#include "MainScene.h"


Store::Store()
{
    winSize = CCDirector::sharedDirector()->getWinSize();
}

Store::~Store()
{
    
}

CCScene* Store::scene()
{
    CCScene *scene = CCScene::create();
    
    Store *layer = Store::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool Store::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    
    //처음버튼, 진행중 버튼, 슬라이더 배경
    //이런 함수도 있구나.. cccontrol류의 다른 함수도 많다 구경해보자.
    
    /*
    
    CCControlSlider *slider = CCControlSlider::create("btn_back.png","btn_back.png" ,"btn_back.png");
    
    slider->setAnchorPoint(ccp(0.5f, 1.0f));
    slider->setMinimumValue( -(60*20-250) );   // 한개 cell 높이 × cell총합 - CCTableView높이
    slider->setMaximumValue(0);
    slider->setPosition(ccp(winSize.width/2, winSize.height - 200));
    slider->setRotation(90);
    slider->setValue(-(60*20-250));            // 0을 무시한다? 무슨말인지 잘 모르겠음
    slider->setTag(1);
    addChild(slider);
    
    //슬라이드 올리기?
    slider->addTargetWithActionForControlEvents(this, cccontrol_selector(Store::valueChanged), CCControlEventValueChanged);
    */
     
     
     
    CCTableView *tableView = CCTableView::create(this, CCSizeMake(1200, 250));
    tableView->setDirection(kCCScrollViewDirectionHorizontal);
    tableView->setPosition(ccp(10, winSize.height*0.3));
    tableView->setDelegate(this);
    tableView->setTag(0);
    addChild(tableView);
    
    
    
    CCMenuItemImage* store_b_backKey = CCMenuItemImage::create("btn_back.png", "btn_back.png", this, menu_selector(Store::onBackKey));
    CCMenu* store_m_backKey = CCMenu::create(store_b_backKey,NULL);
    store_m_backKey->setPosition(ccp(80, 600));
    addChild(store_m_backKey);
    
    
//    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->reloadData();
    
    return true;
}

//슬라이더 콜백
void Store::valueChanged( CCObject *sender, CCControlEvent controlEvent )
{
    m_bTable = false;
    if ( m_bSlider )
    {
        CCTableView *tableView = (CCTableView *)getChildByTag(0);
        //CCControlSlider *slider = (CCControlSlider *)getChildByTag(1);
        
        
        tableView->setContentOffset(CCSizeMake(100, 0));
        //tableView->setContentOffset(CCSizeMake(slider->getValue(), 0));
    }
    m_bTable = true;
}

// 드래그 CCTableView 트리거
void Store::scrollViewDidScroll(CCScrollView* view)
{
    
    /*
    m_bSlider = false;
    if ( m_bTable  )
    {
        CCTableView *tableView = (CCTableView *)getChildByTag(0);
        CCControlSlider *slider = (CCControlSlider *)getChildByTag(1);
        slider->setValue(tableView->getContentOffset().x);
    }
    m_bSlider = true;
     */
}


//테이블 한칸의 크기정하는 함수
CCSize Store::tableCellSizeForIndex(CCTableView *table, unsigned int idx)
{
    return CCSizeMake(300, 300);
}




CCTableViewCell* Store::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    CCString *string = CCString::createWithFormat("%d", idx);
    CCTableViewCell *cell = table->dequeueCell();
    if (!cell)
    {
        cell = new CCTableViewCell();
        cell->autorelease();
        
        //CCMenuItemImage* sprite = CCMenuItemImage::create("btn_attack_00.png", "btn_attack_01.png");
        
        
        
        CCMenuItemImage* sprite = CCMenuItemImage::create("btn_attack_00.png", "btn_attack_01.png", this, menu_selector(Store::onBackKey));
        CCMenu* store_m_build = CCMenu::create(sprite,NULL);
        store_m_build->setPosition(ccp(0, 0));
        //addChild(store_m_build);
        
        CCLog("test");

        
        //CCSprite *sprite = CCSprite::create("MrKo.png");
        //sprite->setAnchorPoint(CCPointZero);
        //sprite->setPosition(ccp(0, 0));
        cell->addChild(store_m_build);
        
        CCLabelTTF *label = CCLabelTTF::create(string->getCString(), "Helvetica", 20.0);
        label->setPosition(CCPointZero);
        label->setAnchorPoint(CCPointZero);
        label->setTag(123);
        cell->addChild(label);
    }
    else
    {
        CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(123);
        label->setString(string->getCString());
    }
    return cell;
}



//셀을 몇개를 출력할 것이냐.
unsigned int Store::numberOfCellsInTableView(CCTableView *table)
{
    return 5;
}

void Store::onBackKey(cocos2d::CCObject *pSender){
    
    CCScene* pScene = Main::scene();
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->replaceScene(pScene);
    
}




/*
bool Store::init(){
    
    if(!CCLayerColor::initWithColor(ccc4(255,255,255,255)))
        return false;
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    
    
    

    ////////
        //테이블 뷰
    //320x320 테이블 뷰 생성
    CCTableView* tableView = CCTableView::create(this, CCSizeMake(320, 320));
    
    //kCCScrollViewDirectionVertical : 세로 스크롤, kCCScrollViewDirectionHorizontal : 가로 스크롤
    tableView->setDirection(kCCScrollViewDirectionVertical);
    
    //추가시 정렬 기준 설정 kCCTableViewFillTopDown : 아래부분으로 추가됨, kCCTableViewFillBottomUp : 위에서 부터 추가됨.
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    
    //기준점 0,0
    tableView->setPosition(ccp(80, 0));
    
    //데이터를 가져오고나 터치 이벤트를 반환해줄 대리자를 이 클래스로 설정.
    tableView->setDelegate(this);
    addChild(tableView, 1, 10);
    
    
    
    //this->addChild(tableView, 1, tagTableView);
    
    //tableCellAtIndex 등등 데이터 소스를 다시 한번 부른다. 테이블 뷰를 다시 그리므로 처음으로 포커스가 맞춰진다.
    tableView->reloadData();
    
    
    
 
    
    
    //backKey 설정
    
    CCMenuItemImage* store_b_backKey = CCMenuItemImage::create("btn_back.png", "btn_back.png", this, menu_selector(Store::onBackKey));
    CCMenu* store_m_backKey = CCMenu::create(store_b_backKey,NULL);
    store_m_backKey->setPosition(ccp(80, 600));
    addChild(store_m_backKey);
    
    
    return true;
}


CCScene* Store::scene(){
    
    CCScene* scene = CCScene::create();
    Store* store = Store::create();
    scene->addChild(store);
    
    
    return scene;
    
}
*/



/*
void Store::onEnter(){
    
    CCLayer::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, true);
    
}

void Store::onExit(){
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
    
}

void Store::scrollViewDidScroll(CCScrollView* view){
    
    
}

void Store::scrollViewDidZoom(CCScrollView* view){
    
    
}

bool Store::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent){
    
    
    return true;
}

void Store::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
 
    
    CCLog("moved");
    
}

void Store::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    
    
}

void Store::ccTouchCancelled(cocos2d::CCTouch *&pTouch, cocos2d::CCEvent *pEvent){
    
    
}



void Store::tableCellTouched(CCTableView* table, CCTableViewCell* cell){
    
}


CCSize Store::cellSizeForTable(CCTableView *table){
    
    return CCSizeMake(320, 80);
}
CCTableViewCell* Store::tableCellAtIndex(CCTableView *table, unsigned int idx){
    
    
     CCTableViewCell *cell = table->dequeueCell();
    cell = new CCTableViewCell();
    cell->autorelease();

    
    CCLabelTTF *label = CCLabelTTF::create("hello", "Helvetica", 20.0);
    label->setPosition(CCPointZero);
    label->setAnchorPoint(CCPointZero);
    label->setTag(123);
    cell->addChild(label);


    return cell;
}
unsigned int Store::numberOfCellsInTableView(CCTableView *table){

    
    
    return 10;
}


*/
