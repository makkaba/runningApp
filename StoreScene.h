//
//  StoreScene.h
//  kingdomCell
//
//  Created by chungkiwan on 2014. 2. 6..
//
//

#ifndef __kingdomCell__StoreScene__
#define __kingdomCell__StoreScene__






#include "Common.h"
#include "cocos-ext.h"

using namespace cocos2d::extension;


class Store : public CCLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
public:
    Store();
    ~Store();
    
    virtual bool init();
    
    static CCScene* scene();
    
    CREATE_FUNC(Store);
    
    
    
    
    //CCScrollView 타입이 뭘까. 파라미터로 넘어오는게 저건데, 가장 중요해 보이는데..
    
    
    
    //스크롤 했을경우
    virtual void scrollViewDidScroll(CCScrollView *view);
    
    //줌을 했을 경우
    virtual void scrollViewDidZoom(CCScrollView *view) {}
    
    //셀이 터치됐을 경우
    virtual void tableCellTouched(CCTableView *table, CCTableViewCell *cell){}
    
    //인덱스가 가리키는 셀의 사이즈?
    virtual CCSize tableCellSizeForIndex(CCTableView *table, unsigned int idx);
    
    //인덱스가 가리키는 테이블 셀 자체
    virtual CCTableViewCell* tableCellAtIndex(CCTableView *table, unsigned int idx);
    
    //테이블뷰에 몇개의 셀이 있는가?
    virtual unsigned int numberOfCellsInTableView(CCTableView *table);
    
    void onBackKey(CCObject* pSender);
    
private:
    
    
    //cccontrolEvent타입은 또 처음본다. 터치를 먹었을 때 수행되는것 같아보이기는 하는데..
    void valueChanged( CCObject *sender, CCControlEvent controlEvent );
    
private:
    
    //불리안 변수 테이블
    bool m_bTable;
    
    //불리안 변수 슬라이더
    bool m_bSlider;
    CCSize winSize;
};







/*
class Store: public CCLayerColor, public CCTableViewDelegate, public CCTableViewDataSource{
    
    
public:
    
    virtual bool init();
    static CCScene* scene();
    void onBackKey(CCObject* pSender);
    
    
    
    
    
    
    
    
    CREATE_FUNC(Store);
    
    void onEnter();
    void onExit();
    
    void scrollViewDidScroll(CCScrollView* view);
    void scrollViewDidZoom(CCScrollView* view);
    
    bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent);
    void ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent);
    void ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent);
    void ccTouchCancelled(CCTouch*& pTouch, CCEvent* pEvent );
    
 
    
    void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    CCSize cellSizeForTable(CCTableView *table);
    CCTableViewCell* tableCellAtIndex(CCTableView *table, unsigned int idx);
    unsigned int numberOfCellsInTableView(CCTableView *table);
    
    
};
 */






#endif /* defined(__kingdomCell__StoreScene__) */
