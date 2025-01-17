#include<iostream>
#include<queue>
#include <cstring>
#include<string>
#include<vector>
#include<stack>

using namespace std;
template <class T>
class BinaryTreeNode
{
public:
    friend void Visit(BinaryTreeNode<T>*);
    friend void InOrder(BinaryTreeNode<T>*);
    friend void PreOrder(BinaryTreeNode<T>*);
    friend void PostOrder(BinaryTreeNode<T>*);
    friend void LevelOrder(BinaryTreeNode<T>*);
    T data;
    int height;
    BinaryTreeNode<T>* LeftChild;    // 左孩子
    BinaryTreeNode<T>* RightChild;   // 右孩子
    int bf;
    BinaryTreeNode() {}
    BinaryTreeNode(T data) : data(data), LeftChild(nullptr), RightChild(nullptr) {};
    ~BinaryTreeNode() {}
};
template <class T>
void Visit(BinaryTreeNode<T>* x)//输出当前节点的值
{
    if (x)
    {
        if (x->LeftChild && x->RightChild)//左右孩子都在
        {
            cout << x->data << "(" << x->LeftChild->data << "," << x->RightChild->data << ")"<<" ";
        }
        else if (!x->LeftChild && x->RightChild羳蕷�5曈龛:6巳謼柪4瞸x�?O廄�h⺌f�抎	\録&媋絾
樀唄翌惎�8��z昍e猥}p帎�<樊翾鱊k�/騍嘓�/喌z嶜2厒5FV儥RW�Kお幋瘭艫氪o�<Zu蜎彩� �鵒sX
]宽
骼�`j蒚摙慄PO﹎ln岉崷
眮+xM灰鬿 
傜各濓眍m/髌�瘏/.隿淽湥/g/Β}蓮�%$頱灗�.岕b�,4�%L瓋厮嶊亅Cl�6甙W厢w襙顁!7満藓"0�嚣�?O0Ko?Kt鬼淥�>蟱|^預)c\仴(嘊�@脽羼xO�?LR譩潅殩U鏌�?qW鯲u>_>i9敤S殸J� 緙�*Q曟奼愫蚷:v[閽鍦鎎8!薚碲硏a蠖?y"1瓞�%$燚刍惖鶷籼5ǘo�]�4豋�??��G瘬〆騚,棐7⒊泑欕橪�劍柊X�袙4腝2|nS9侩靛B秖5燴NN.
揦赭锥�+XU	�刜塦2鏋�'v檥纼莸胑Fv\[?~L�(;Y@m'XV�5尛君whD� 吳晴[�&Ijn皙k]麪渪_艟崊�	�鼲E雄v,
踋[��┢啂暜] /餏褢%薂裕PG�]y>砘�	z禯Z臣畊蟴u斔��:��
>袄k �_4葩風{嬟z㈤0`�3!鎒N孪S!3"[�晻4]p=[鳊�,埸匣懫a�呠 浍��*zLM蓳�5�#隕`b�>燐谀7硧>9}澖頖%仏搆晲蹬篍内誴8儃鸗吿蘽.岖毛鄮?鉵UJ銞�
莯蟴u¤+i甶分Qu赑蹀708唱�梌孳��25X�Oe:}鷵呮哿Xb棞惠飿N漺>颫#G跉䦅暲A凳焦渌肝"矘橻�<瑟佲﹞r
�;莩�tG劎;氣瀋~嘯�焤�x3y4妓ygPyNx蚟gw鎕�"岣.┱�	彬 �灥0�粙Jf樃ni��m�茍pv�-趀
&G	*G瓔MG鹖�'x眄r攑斈=擙v瀟lt�:稶t緳踲{OO!RF槏執h6液n蠄擿*皦瘪璏鞗扒�預\撧`�>k#魯�?荤�&*~�� '齟�釲_<}- 曤�绬T1課 6 *伏}�< r�#b|芠DG #褻k閧zV�銅瞭诎駷:鍫�鱎壘x�6Sr鳽儲Xzу膏銺_u斖�$�椔砓岖牒鷑峭篩扆阐m霕z贳��>催*bY農砧磼桑P�7*頹\7冱h��0pv[^奏�"y姈f芩R囑
触L糺蕦Q泱���<ミ竲8<�秝豜氻�蛥铓�=�;灮S�1朏咯#囦姛撱極Q噵垭O<�&璒^_~'Xm�(A檈刓且鼭+C堗{象�尃O�网鋿逹揯櫲lcs���? 迫#��4af姊"�;+PQZ9_:�た6��+iZ�蛾9�� ~�7簰瀄桻+`U觸�鐙|摑\l祇�(韲�锊%K岞K欼饱綗Kl殉P阌a鰣秘�!禽縦.錴�7kㄦj:膇壀轔嚂.�?6T8鐧T>![&蜻�;H�>=E廖�:P#捫��U E>^饮�8�G��<%簦V$��撚呉M�?V�c�偺07橊狤I潸悦:崑銒p滷u曉Z單R*��橣7h颃o,R	{R1謖�.	_櫂镃2輭訤dXCB筱Y尠C=3=躙�锶n慶$!p:娶莧婡!蚵{�,哞Z垯┑(K埸x綖4勐�瘧暨蚳俳B'3i�(_聕N/[  g �Aj瘳H娆9�=e���黢<�/熲"痠X�揠渪9�9�餆垻T?�)�#s|涹+眈呭挳t亮�+k嚮芣d鐿�蟀兀怚,欯陇忠G�"#镯珏閅到t�J�$遣尰靑矲叧L�И樌u麊赎嗭畲囍鉹!U�*�O徻W#&#逨篱囧姴募戟8蹣&|jM﹗xt_"骇�4精摔瀟纯b.椕
醃[�|櫫潍yW礵Ks�424)焑玮e默e� 舀裥酧�s�?蹉%D`C招磱XJ皌g糳縋瀄een餔J@凶癤恍嶾媤熵?耐6註�靔`��'苂请興ゾ0笨閊麽6}f蚤x瞇蓦捤銩筌~ g^y�詚O畜$Um熠紞窷�NF靣Ss疄k;碟$跌楮嘘痞玃�E暇开)浿P�颧鋨J�顩笏JQ藿W@�.芲h犯炋d鈈f'�5耆/芓�.i蒏T糍|b'W呀�4�$�)銑HT_臦
(嶯溗荙犗f\b僁-?蓵RqpS�+邂8診螄
卛験y窓镠縏綈鄆nfR诿蚙Bj'\�瞐Y[ㄦ徑纜牊~垽躓�-;��B-�&I廧#L蜚C(飡X5:t�s撜鄠夑�<錑蚥>牧硭鶔��	焏瓬l蘻棖w悖G鸖�9/甍|璤5�朦顳e聁{纩儽1;弸瑾�鳘
J^N紛弘餀岟顃痥x"@�%
�J�$垼L.姐厞摮3鶧蓨o餻�湙藌b闪"咕w誳x�<箏渭~�=q5 �<e潀鱰`尝H�嫷jf#I厅橘�D5挖跰�罙<��9妍脍鈶E蔀鵭�
)}�漺�賉;顙�诲釈碿67儥�.鍈�:厀宷�&�+脓J婙�煃P~5衳蜁��怉�j�
<緟果廹7宲鋁賘 e
凂c騮y溸/轡]];+>淊�"$;xs�8鑢4�K`槐Y艂U糘-閵絗v�kuu簔g{ xe�6臢柱饙gU`N諢酲Hw梤洆自豇xC錊GG�;8倵憰曞H傂[鹑鰁}�伏Wh邈�+餣s�'痑
w踼P>蘙鯩汢v%腴煿j緉+朽m#�j┐+�糀�冓��,p骷n�F骰$�,�9V爞g�5B�~D鴒Vv冯倨� �GC=:]陶6赡IFnK�m?%底聪23N3u~�#F磪剌鰧骏厖	匮喗�溌涑K�9�,d★譪;找灊挏斢訇泥躰�*賕A�5(n�;VX鍎禈q緓p�<=6�-:V滌m���).�1撢IN~}盎闏SzSx�侂苣�-苘�灡倹獨授贺簶趈z壍4]枋岴�祙ge<W]Ols鐚囉7Pb玮醝槽 =�郹`雞f摌簄箊]>鄝�.邚N�安核`�)攂G喝}^ca器 t跤c貼
~k漴�	qt�,�.尨衺K"0&砣�x噁坵�2|讑摟u厊gr哔�:Wc�l�8瀏化↘r/獛簲焳当_伯鋢u��A54艻z�-h螘_� $r竓 �胘#8�<�V>�昫鎀禩硦>彐頬騸<簐辎硏b赠醝��#)�Wm�*%G\扲
nor$�:�"鷿测w縒9珥錖鞋锴遽�5消髾|=T﹥h缬城馀誙欀�1鍝�
歽MuQ蝊�-靘;洅CVX'嬔dmBJ�>_H喾閅<j籿琸�5�606W枆@畳iyr�寓h�:�+$铤q桍u詤罴RA! 繼To瑮柝bE$p朴仲%ZB区閜剖N`禰累筈�(阿jに{蒟t*鯴詳饗阒A#y锰cJ2�5,,萞^Buk缰榊iwk謟蘆w\K��&闱�i�%�"煷�*v�7r5?超Xje枛隳&3�疦輖鋃H>�b�傧臵[蔺鄠��_靁~韝髑嗬垦F袀�2-跧澯s"��3麆7,\[燘貙圎xBl麯�o*|a5涜m餧�术轨踎a
讬H燍p[彭��v篳蒝�<芠M�2VW躈桏鄷緧趍)遖鍵'鑟奌化U玙琌瀥縘5e繑庯)}郎'鹣GN節煒滖肪墓�0A蜷l�GPn�+ヘ�-嚆)”kW}荖LX*XV!��55軴|yRoǖ粉鱪T霮�禬辘�鉙松�儰bi�夁鑑F7柑乌Jn�6颫!愦�7v锼薪\搤M�7�8巜!褜N瀡�哦�8+镣P]�,厯*h挒P!缂/r?D#�&3緑戾�D堪#鵟韖嶮边T�]楃覐Q�;荋h]-Y哌軈畆^政*�0栓肨羇f"}�^H:輅纠\l�y~疔n齰#獵鮊�c9冋~4��B�Q峻筒懂涩v啣R廬︾牪5.F辭�2撨灅忑!澢�烂髤玤腽pw.噅E朼篙a塮%噳壠�顙翮榑&�躕硠E]{簎&刏�;鼬a�$蠮?5]]CJ322郊匠A7J�'�&�",E�%�D杦M斠
�マ7z}�帮葏蹅ci悻ǜQ�?B簵�竟? 沠/+镩m 鞡1緶簹5Kr�5�/� 宍睨喪CI�
yHE�:k�3tD齣<功�1g	xXv撛�隁w^R盬�羬�0�9霏8xО�8⿹檉痥BP垽0R�寞娦U俯a9-穡^栕慎�=▍;淎_翵ao頁;鹶 臚��r獲1W[ε蒚7紒r譯�4:�B艉枈�-K顦煿眱着��憖Y擝崑$髭礞霢爺跁�阘谍5O,Vi忾慑(存�D�6諒Ec蓚p�遯韬X山鸮T县]�4="敼浺�峐櫡v砩祣V蕽叕籛颱窪診!{E锠邜�%迨D熋~+佉A	+O契�躯蝒﹊逎uI�挹8]痬櫉rkV!�+m揻鶖 ��廑划%C莢�6餱2|Y偌j袆u憬え衵a�8mW泚_R�=f昻G7/柂�0�6;33傓揹亏嶆─洴苲�雪�%愑T裌K |&痀琀Z�7┿区aN鸵譗1欷rh氵轔�sL浐��?e?犓|i.7忪e*NY當籢J詉紸-跂鱥逶騫p頧Y?��&5v>可;脡-瀋縺�偝nC6蘞匈聙qi螛W0��$敘M?楦蘌5嬎\鸽忉枒L灏柜拘豢鸰彌舱Xa�1fl/郌砑-�4_t績茂�/w�'�逋l�6岒棃劾V=���zy�&o�%k髻�诹a尝�劙T	`H扟�K現�;T!t緹��鋣c悗S�"qT2h�'S鰵�&2犈车	rvjq啕砰p胠%榎挫�+u3Y泄φmO篤羣��涿潁�盬?Y絆鸂u裼螜F*|�%蕴晱哚 v7氽嚏鯈愱ｏ<E�蒓mN貺|祃鉘6�樳呝鳸
吾竲&�?#摌殪VI		�(舚f"�87辄夻偱棞�KNl?眪2b42�.�8D镵�吚`~嶢�J濿P镧m�騚T鳣桮>桯�'�夀z�q褟�凜荡4裔簯釢椐汱2�C�9�虏河莞\寭1[瀉j�盻鉻� 體F蛣_陏}z49"et:[噺縪鐣閅肸蔝炎�>�?欉xj綽T硷讛舭�8)6篟qGnSY隴鷖U4N"r<�d�zw�3?`YZ税#飹頦4�龘�Sc�-;�
R鷿qK瞂4�1�4薳悛k?уxr陸��虈続x8斓!礶UW�;眿虤亳婋Q釶髿w銟緿槻璠奻J抧F<8攥Wn�-��!�鋢h耡骑�邟{C�8f� 棬拮瘋稌L攔)馢i櫞壌>x李滳�	_O憣R塬!O謴IU器店�Y嬌..�*<┪;锦�.Y眍簹�$煛MH緂K_"�姓喴'$Y炶蚕剬L涹.,懄鹡C��肖&v熍d�<靼O鄯N�)�+3T闗�9鰢F譇8c't9鎘钫照&R嚽�%鹂f�9�$铄桻p 槿荱se$`RmG┩�熫4~Z鼿�(l跉-�-鏮侹�8m�2>x斂审�sk�r�5蛝薬�廐l7鎴�
湎Ku脩x鰼掆{U0pf6豞"yrW{U瓥j�(瑩櫹>JQ懕q@餐�籃�蒊�-E筢4雖柡B弇耠;钖d茮A�+桹�醨B蘿�4瀛5揵簵rA踿锅窷蘧�76苑铖o#C鈝？nD�E��E�鱳v."Omm錰趧勢洉帿仙g蝨鏃�5].嘖N瑨詹�:Gt浊媷`bo渧睿枮��#殀鼼O纊}}躮膇F;沊永Z6g9!單h�%zI�)9穻=氰x<OsU闞�覘�%燲腞烈R�:糗纟Q雡�2r晋`�9��(1�~媧訊直俰-铛	/发z&炡.63鳔竭靕詨@f捨6麋�=椁>礨疔.怔藼q鑯┭QO坲縳孞魅h�Z贎蕕軟d@O�j`麤wL羮 '湔詌�2鰉叻~剣胑詮�8S珩:�3养�?{櫷Fj+鶲踝曾|P+祃pl��莑0-c保f@�檭P崊-CN隃p翤謐甫[��妬��硺� ^Q�3蔃�MXB%h�維�贼\�.纉!稉参蟸予*r牚�啼h裔[Rｉs�?.億/=&招瀱襟�粝1\鷣&�'L錑隌�)T捅隧�燂d碘孆炦 �4廨港�$剦饷爒嬊p椪兞i]XQ6俛罓比!N犥儆萼軠鼗LZ'馲~TQxYYf繹傥z镕鮰顩'悆w谘钧ゥ硞7�%��阬*��(.蕒狵q�㎞i朻}民覛椴邤�[裫桹憑娃蜪%GZ\b|x垗f]�*G洦俟箪���	堁(Mp(
笻}p鴅埭庫痣,鷘6�)>(恄�%1暰=雽w4S�3?�?wGLoＺK��	幘冇sZ�_m鯹鏇樵Z	瀜嬂bc昽�i�(俉0<鰲�@`譝I[�(橸尪}中独挘MpX豓�Y{{f漘仠�?庠禨�H�眊o��<捥趋�#雕p禒F住艀⒖vvm#赚赚eA軆H{Ρ-缦*z傸�e魽聂<|隘訰$�pk�R>{焱薹涴�	智�漁燸]�{=?辦n+�'}嬍k�:�4钝數3医榭q[D膑��9m蟟|埊繹;甎T�Tx彇� 厂萜HS碍wJ� H陟锯y��"mLx赺9^Uokr�3j=Fb韙俳]LZ歺u鋘�,2蜚湗~]�/r韤溣7�4S琊U|湳��呎釸忖襾K峐�/骪7述黊赤錴欭	亳 }
        else
        {
            cout << "Wrong";
        }
    }
    //建立一个节点，并将该节点连接至pp
    BinaryTreeNode<T>* r = new BinaryTreeNode<T>(node);
    if (this->root) 
    {// tree not empty
        if (node < pp->data)
        {
            pp->LeftChild = r;
        }
        else
        {
            pp->RightChild = r;
        }
    }
    else // insertion into empty tree
        this->root = r;
}
template<class T>
void BSTree<T>::CreateBSTree()
{
    int i;
    BinaryTreeNode <T>* t = new BinaryTreeNode <T>(this->origin[0]);//根节点
    root = t;
    this->root->height = 1;//建立根节点
    for (int i = 1; i < origin.size(); i++)
    {
        BSTInsert(this->origin[i]);
    }
    return;
}
template<class T>
bool BSTree<T>::IsAVLTree()
{
    for (int i = 0; i < origin.size(); i++)//算bf左子树高度-右子树高度
    {
        if (Find(this->root, origin[i])->RightChild == nullptr && Find(this->root, origin[i])->LeftChild == nullptr)//左右子树都是空的
        {
            Find(this->root, origin[i])->bf = 0;
        }
        else if (Find(this->root, origin[i])->RightChild == nullptr&& Find(this->root, origin[i])->LeftChild != nullptr)//右子树空
        {
            Find(this->root, origin[i])->bf = Height(Find(this->root, origin[i])->LeftChild) - 0;
        }
        else if (Find(this->root, origin[i])->LeftChild == nullptr&& Find(this->root, origin[i])->RightChild != nullptr)//左子树空
        {
            Find(this->root, origin[i])->bf = 0 - Height(Find(this->root, origin[i])->RightChild);
        }
        else
        {
            Find(this->root, origin[i])->bf = Height(Find(this->root, origin[i])->LeftChild) - Height(Find(this->root, origin[i])->RightChild);//左右子树都不是空
        }
    }
    int flag = 1;
    for (int i = 0; i < origin.size(); i++)
    {
        if (Find(this->root, origin[i])->bf == 0 || Find(this->root, origin[i])->bf == 1 || Find(this->root, origin[i])->bf == -1)//算bf，如果不是-1,0,1，就是不平衡的
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
template <class T>
BinaryTreeNode<T>* BSTree<T>::LLRotation(BinaryTreeNode<T>* k2)//左单旋
{
    BinaryTreeNode<T>* k1;
    k1 = k2->LeftChild;

    k2->LeftChild = k1->RightChild;
    k1->RightChild = k2;

    return k1;
}
template<class T>
BinaryTreeNode<T>* BSTree<T>::RRRotation(BinaryTreeNode<T>* k1)//右单旋
{
    BinaryTreeNode<T>* k2;
    k2 = k1->RightChild;

    k1->RightChild = k2->LeftChild;
    k2->LeftChild = k1;

    return k2;
}
template<class T>
BinaryTreeNode<T>* BSTree<T>::LRRotation(BinaryTreeNode<T>* k3)//LR
{
        k3->LeftChild = RRRotation(k3->LeftChild);
        return LLRotation(k3);
}
template<class T>
BinaryTreeNode<T>* BSTree<T>::RLRotation(BinaryTreeNode<T>* k3)//RL
{
    k3->RightChild = LLRotation(k3->RightChild);
    return RRRotation(k3);
}
template <class T>
BinaryTreeNode<T>* BSTree<T>::AVLTreeInsert(BinaryTreeNode<T>*& tree, T node)
{
    if (tree == nullptr)
    {
        // 新建节点
        tree = new BinaryTreeNode<T>(node);
        if (tree == nullptr)
        {
            return nullptr;
        }
    }
    else if (node < tree->data) // 应该将key插入到"tree的左子树"的情况
    {
        tree->LeftChild = AVLTreeInsert(tree->LeftChild, node);
        // 插入节点后，若AVL树失去平衡，则进行相应的调节。
        if (Height(tree->LeftChild) - Height(tree->RightChild) == 2)
        {
            if (node < tree->LeftChild->data)
                tree = LLRotation(tree);
            else
                tree = LRRotation(tree);
        }
    }
    else if (node > tree->data) // 应该将key插入到"tree的右子树"的情况
    {
        tree->RightChild = AVLTreeInsert(tree->RightChild, node);
        // 插入节点后，若AVL树失去平衡，则进行相应的调节。
        if (Height(tree->RightChild) - Height(tree->LeftChild) == 2)
        {
            if (node > tree->RightChild->data)
                tree = RRRotation(tree);
            else
                tree = RLRotation(tree);
        }
    }
    else //key == tree->key)
    {
        cout << "Wrong!" << endl;
    }
    return tree;
}
template <class T>
void BSTree<T>::AVLTreeInsert(T node)
{
    AVLTreeInsert(avlroot, node);
}

template<class T>
void BSTree<T>::CreateAVLTree()
{
    int i;
    BinaryTreeNode <T>* t = new BinaryTreeNode <T>(this->origin[0]);//根节点
    avlroot = t;
    for (int i = 1; i < origin.size(); i++)
    {
        AVLTreeInsert(this->origin[i]);
    }
    return;
}

int main()
{
    BSTree<int>bstree;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        bstree.origin.push_back(m);
    }
    bstree.CreateBSTree();
    cout << "非递归升序输出：" << endl;
    bstree.NInorder(Visit, bstree.root);//升序输出
    cout << endl;
    if (bstree.IsAVLTree())
    {
        cout << "True" << endl;
        bstree.LevelOrder(Visit, bstree.root);
    }
    else
    {
        cout << "False" << endl;
        bstree.CreateAVLTree();
        bstree.LevelOrder(Visit, bstree.avlroot);
    }
    return 0;
}