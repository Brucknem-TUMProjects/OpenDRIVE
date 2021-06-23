#include <OpenDRIVE/utils/LongLatProjector.hpp>
#include "gtest/gtest.h"

#include "HDMapTests.hpp"
#include "OpenDRIVE/utils/Projector.hpp"

namespace opendrive {
    namespace tests {

        /**
         * Base setup for the geometry calculation tests.
         */
        class ObjectTests : public HDMapTests {
        public:
            /**
             * @destrcutor
             */
            ~ObjectTests() override = default;

        protected:

        };

        /**
         * Tests that calculating the objects world position from the s and t coordinates works.
         */
        TEST_F(ObjectTests, testObjectWorldPositions) {
            std::vector<Vector> expected = {
                    {6.95857459616236621514e+05, 5.34614971628805343062e+06, 5.32971484912490836905e+02},
                    {6.95924292717217002064e+05, 5.34637409276820439845e+06, 5.32264344457847414560e+02},
                    {6.95713793015561648645e+05, 5.34574680699157994241e+06, 5.32205698545778204789e+02},
                    {6.95679357083367533050e+05, 5.34554943678468465805e+06, 5.34626726982279592448e+02},
                    {6.95880223420403664932e+05, 5.34630694837388116866e+06, 5.31012853087240159766e+02},
                    {6.96023792366118053906e+05, 5.34670922393952962011e+06, 5.31311930203277142937e+02},
                    {6.96109265645239502192e+05, 5.34699644647382292897e+06, 5.30659656139404432906e+02},
                    {6.96058731418506475165e+05, 5.34689597237328346819e+06, 5.29132972618126586895e+02},
                    {6.96122833140023401938e+05, 5.34704199089933931828e+06, 1.06012455767105484483e+03},
                    {6.95852676229589502327e+05, 5.34613351803871151060e+06, 1.06513625969218219325e+03},
                    {6.95969236430817283690e+05, 5.34652547313298843801e+06, 1.06248389554123423295e+03},
                    {6.96050324274386744946e+05, 5.34679809797762148082e+06, 1.06109742521980024321e+03},
                    {6.95865962375744595192e+05, 5.34617827535422332585e+06, 1.06479014556672086655e+03},
                    {6.95671804167340742424e+05, 5.34560859551504347473e+06, 5.33313964218507976511e+02},
                    {6.95816162497487035580e+05, 5.34609616797826625407e+06, 5.31989738928076008051e+02},
                    {6.95942449474101886153e+05, 5.34652105707536544651e+06, 5.30676108187322938647e+02},
                    {6.96041193895652191713e+05, 5.34676187438863329589e+06, 5.30695791890884720488e+02},
                    {6.96102904909026110545e+05, 5.34704655023154523224e+06, 5.28862805734843391292e+02},
                    {6.96088973664717515931e+05, 5.34699894415640272200e+06, 5.29079185319867065118e+02},
                    {6.96074727971517713740e+05, 5.34695100928375218064e+06, 5.29226931543150840298e+02},
                    {6.96060753790526301600e+05, 5.34690321995288971812e+06, 5.29353419558169548509e+02},
                    {6.96046934231985127553e+05, 5.34685568709443509579e+06, 5.29468143751399566099e+02},
                    {6.96032666943316464312e+05, 5.34680788041877094656e+06, 5.29550929107770457449e+02},
                    {6.96018336510702967644e+05, 5.34676014458747301251e+06, 5.29635837182283239599e+02},
                    {6.96003549342793994583e+05, 5.34671278442453406751e+06, 5.29772728444111521640e+02},
                    {6.95986961014502216130e+05, 5.34666570928101893514e+06, 5.29810850591320445346e+02},
                    {6.95972844326455844566e+05, 5.34661805555170215666e+06, 5.29981902665139386954e+02},
                    {6.95958899045972852036e+05, 5.34657098715103138238e+06, 5.30090714911392865361e+02},
                    {6.95944536736381356604e+05, 5.34652311409443244338e+06, 5.30180274492730291058e+02},
                    {6.95929588508132146671e+05, 5.34647308859651908278e+06, 5.30275327239401008228e+02},
                    {6.95917712258279556409e+05, 5.34643321890187822282e+06, 5.30388293930194890891e+02},
                    {6.95900945167536963709e+05, 5.34637735941862873733e+06, 5.30587833124660164685e+02},
                    {6.95886850662800716236e+05, 5.34632957322453148663e+06, 5.30766203260200654768e+02},
                    {6.95872919807875645347e+05, 5.34628190525054838508e+06, 5.30900849426808576936e+02},
                    {6.95858677944850525819e+05, 5.34623405828339792788e+06, 5.31054848512036869579e+02},
                    {6.95844469978431356139e+05, 5.34618643077207915485e+06, 5.31321344298203598555e+02},
                    {6.95830203299628570676e+05, 5.34613875847665313631e+06, 5.31497165586366918433e+02},
                    {6.95816171102638938464e+05, 5.34609096487812977284e+06, 5.31514678317332709412e+02},
                    {6.95801824366636690684e+05, 5.34604282690606825054e+06, 5.31602140474360112421e+02},
                    {6.95786996070592897013e+05, 5.34599350750705320388e+06, 5.31820688327689140351e+02},
                    {6.95772869723279494792e+05, 5.34594585783720575273e+06, 5.31994291214237591703e+02},
                    {6.95758596873435541056e+05, 5.34589804343490861356e+06, 5.32111278237354326848e+02},
                    {6.95744395209637819789e+05, 5.34585031264606770128e+06, 5.32229761124253286653e+02},
                    {6.95730248203609371558e+05, 5.34580246175097208470e+06, 5.32344465713047839017e+02},
                    {6.95716043810550007038e+05, 5.34575452399626374245e+06, 5.32474645510750406174e+02},
                    {6.95701947739025694318e+05, 5.34570686741886287928e+06, 5.32592718055607406313e+02},
                    {6.95687977118393173441e+05, 5.34565917395519185811e+06, 5.32685709679732667610e+02},
                    {6.95674006530827027746e+05, 5.34561137651211861521e+06, 5.32779601934169932065e+02},
                    {6.95659891402107779868e+05, 5.34556383105926029384e+06, 5.32915965230506799344e+02},
                    {6.95645059904740890488e+05, 5.34551420404412131757e+06, 5.33029578491784945982e+02},
                    {6.95630814145503798500e+05, 5.34546648966754134744e+06, 5.33129525168356281029e+02},
                    {6.95616740644038887694e+05, 5.34541893301900383085e+06, 5.33155834360592280063e+02}
            };

            int i = 0;
            for (const auto &entry : roadHighwayNorth.getObjects()) {
                auto position = roadHighwayNorth.getWorldPosition<Object>(entry.first);
//                std::cout << "{" << position << "}," << std::endl;
                EXPECT_NEAR(position.getX(), expected[i].getX(), maxDifference);
                EXPECT_NEAR(position.getY(), expected[i].getY(), maxDifference);
                EXPECT_NEAR(position.getZ(), expected[i].getZ(), maxDifference);
                i++;
            }
        }

        /**
         * Tests that calculating the objects world position from the s and t coordinates works.
         */
        TEST_F(ObjectTests, testObjectGoogleLinks) {
            std::vector<std::string> expected = {
                    "https://www.google.de/maps/place/48.2462725667135572393817710690200328826904296875,11.6415849019957899912469656555913388729095458984375",
                    "https://www.google.de/maps/place/48.24584902923968598997817025519907474517822265625,11.6413754038497021525699892663396894931793212890625",
                    "https://www.google.de/maps/place/48.245422633565084424844826571643352508544921875,11.641161526039180529323857626877725124359130859375",
                    "https://www.google.de/maps/place/48.24499746145131240382397663779556751251220703125,11.6409513725547295592832597321830689907073974609375",
                    "https://www.google.de/maps/place/48.2445745460259018955184728838503360748291015625,11.640743421880433317028291639871895313262939453125",
                    "https://www.google.de/maps/place/48.24414930771002474330089171417057514190673828125,11.6405293238098987984585619415156543254852294921875",
                    "https://www.google.de/maps/place/48.243724725119335516865248791873455047607421875,11.6403144126175259742694834130816161632537841796875",
                    "https://www.google.de/maps/place/48.24330365945230170154900406487286090850830078125,11.640093533710302864392360788770020008087158203125",
                    "https://www.google.de/maps/place/48.2428857115683484835244598798453807830810546875,11.63984855644620353132268064655363559722900390625",
                    "https://www.google.de/maps/place/48.2424617992254383125327876769006252288818359375,11.6396365703976076844128328957594931125640869140625",
                    "https://www.google.de/maps/place/48.24204309391851808186402195133268833160400390625,11.6394271649967055992647146922536194324493408203125",
                    "https://www.google.de/maps/place/48.24161728536981996739996247924864292144775390625,11.6392117800281500450410021585412323474884033203125",
                    "https://www.google.de/maps/place/48.24117231283792506246754783205687999725341796875,11.6389875199882482093016733415424823760986328125",
                    "https://www.google.de/maps/place/48.2408176633969532076662289910018444061279296875,11.638809292284872043410359765402972698211669921875",
                    "https://www.google.de/maps/place/48.2403208203015338995101046748459339141845703125,11.6385578702618293078785427496768534183502197265625",
                    "https://www.google.de/maps/place/48.23989570766872958529347670264542102813720703125,11.6383461434605539608355684322305023670196533203125",
                    "https://www.google.de/maps/place/48.23947160647771426056351629085838794708251953125,11.6381366766759271058617741800844669342041015625",
                    "https://www.google.de/maps/place/48.23904599221476274806263973005115985870361328125,11.6379229465217548522559809498488903045654296875",
                    "https://www.google.de/maps/place/48.2386223393003348292040755040943622589111328125,11.637709777535139465953761828131973743438720703125",
                    "https://www.google.de/maps/place/48.2381983015421695881741470657289028167724609375,11.6374958016118199566335533745586872100830078125",
                    "https://www.google.de/maps/place/48.23777310070357771110138855874538421630859375,11.6372849278519421289956881082616746425628662109375",
                    "https://www.google.de/maps/place/48.23734490152359200010323547758162021636962890625,11.637069666983141047467142925597727298736572265625",
                    "https://www.google.de/maps/place/48.2369062327089324071494047529995441436767578125,11.63684738535999230180095764808356761932373046875",
                    "https://www.google.de/maps/place/48.23648235299017272836863412521779537200927734375,11.636635322586858620752536808140575885772705078125",
                    "https://www.google.de/maps/place/48.23605703751309192739427089691162109375,11.6364212164469318366855077329091727733612060546875",
                    "https://www.google.de/maps/place/48.23563245102973695566106471233069896697998046875,11.636208110269986804041764116846024990081787109375",
                    "https://www.google.de/maps/place/48.2352067677603741913117119111120700836181640625,11.63599568755984847712170449085533618927001953125",
                    "https://www.google.de/maps/place/48.2347803210825105679759872145950794219970703125,11.635782456379683225122789735905826091766357421875",
                    "https://www.google.de/maps/place/48.234356367512447150147636421024799346923828125,11.6355708159385091704507431131787598133087158203125",
                    "https://www.google.de/maps/place/48.2339320432454741194305825047194957733154296875,11.6353608497011205002991118817590177059173583984375",
                    "https://www.google.de/maps/place/48.2335067839993456573211005888879299163818359375,11.6351508394953402358851235476322472095489501953125",
                    "https://www.google.de/maps/place/48.23308383357747430864037596620619297027587890625,11.634939004869128353902851813472807407379150390625",
                    "https://www.google.de/maps/place/48.2326423960258097167752566747367382049560546875,11.6347165761837754160978875006549060344696044921875",
                    "https://www.google.de/maps/place/48.23221796673794159460157970897853374481201171875,11.634502913753390629381101462058722972869873046875",
                    "https://www.google.de/maps/place/48.23179490138358715967115131206810474395751953125,11.634291644977398760829601087607443332672119140625"
            };

            opendrive::LongLatProjector projector(highwayNorth->getGeoReference());

            const char *type = "pole";
            const char *name = "permanentDelineator";
            int i = 0;
            for (const auto &entry : roadHighwayNorth.filterObjects(type, name)) {
                auto projected = projector.project(roadHighwayNorth.getWorldPosition<Object>(entry.first));
                auto link = LongLatProjector::toGoogleMapsLink(projected);
//                std::cout << "\"" << link << "\"," << std::endl;
                ASSERT_STREQ(link.c_str(), expected[i].c_str());
                i++;
            }
        }


        /**
         * Tests that filtering the landmarks gives the correct objects.
         */
        TEST_F(ObjectTests, testFilterRelevantLandmarks) {
            const char *type = "pole";
            const char *name = "permanentDelineator";
            auto landmarks = roadHighwayNorth.filterObjects(type, name);
            ASSERT_EQ(landmarks.size(), 35);

            for (const auto &entry : landmarks) {
                ASSERT_STREQ(entry.second.getType().c_str(), type);
                ASSERT_STREQ(entry.second.getName().c_str(), name);
            }
        }
    }// namespace tests
}// namespace opendrive