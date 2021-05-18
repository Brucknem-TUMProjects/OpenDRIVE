#include "gtest/gtest.h"

#include "HDMapTests.hpp"
#include "OpenDRIVE/Projector.hpp"
#include "OpenDRIVE/Projector.hpp"

namespace opendrive {
    namespace tests {

        /**
         * Base setup for the projection calculation tests.
         */
        class ProjectorTests : public HDMapTests {
        protected:

            std::shared_ptr<LongLatProjector> projector;

        public:
            /**
             * @destrcutor
             */
            ~ProjectorTests() override = default;

        protected:
            void SetUp() override {
                HDMapTests::SetUp();
                projector = std::make_shared<LongLatProjector>(highwayExitSouth->getGeoReference());
            }

        protected:
        };


        /**
         * Tests that the projection along the geometries produces correct long lat coordinates.
         */
        TEST_F(ProjectorTests, testSimpleForwardBackward) {
            Vector coord{11.639188, 48.241606};
            Vector projected = projector->project(coord, PJ_INV);
            Vector result = projector->project(projected);

            ASSERT_NEAR(result.getX(), coord.getX(), 1e-6);
            ASSERT_NEAR(result.getY(), coord.getY(), 1e-6);
        }

        /**
         * Tests that the projection along the geometries produces correct long lat coordinates.
         */
        TEST_F(ProjectorTests, testProjectionOfStartCoordinates) {
            Vector projected;

            std::vector<Vector> expected = {
                    {1.15945787742606931658428948139771819114685058593750e+01, 4.81776008106349777904142683837562799453735351562500e+01},
                    {1.15944315382777514145118402666412293910980224609375e+01, 4.81774252198616537157249695155769586563110351562500e+01},
                    {1.15942234131881889425130793824791908264160156250000e+01, 4.81771767888077135921776061877608299255371093750000e+01},
                    {1.15939725944763001308501770836301147937774658203125e+01, 4.81768790750348188112184288911521434783935546875000e+01},
                    {1.15937972010443814951941021718084812164306640625000e+01, 4.81766704858862624405446695163846015930175781250000e+01},
                    {1.15936527477384352380340715171769261360168457031250e+01, 4.81764978341072520606758189387619495391845703125000e+01},
                    {1.15935138845714433841749269049614667892456054687500e+01, 4.81763298904701997571464744396507740020751953125000e+01},
                    {1.15934190956392466631541537935845553874969482421875e+01, 4.81762176439295544128071924205869436264038085937500e+01},
                    {1.15933179874727301239545340649783611297607421875000e+01, 4.81761169283318793077341979369521141052246093750000e+01},
                    {1.15932364803108782780327601358294486999511718750000e+01, 4.81760379412764407902614038903266191482543945312500e+01},
                    {1.15931242812564594402147122309543192386627197265625e+01, 4.81759259489254176855865807738155126571655273437500e+01},
                    {1.15929930878437943420067313127219676971435546875000e+01, 4.81757741008880699951077986042946577072143554687500e+01},
                    {1.15928405792098505600051794317550957202911376953125e+01, 4.81756003793197535856052127201110124588012695312500e+01},
                    {1.15926620844483920791390119120478630065917968750000e+01, 4.81754243034824725100406794808804988861083984375000e+01},
                    {1.15924252464203441093104629544541239738464355468750e+01, 4.81752461898904229542495158966630697250366210937500e+01},
                    {1.15922329755307806919972790637984871864318847656250e+01, 4.81751435023489804621021903585642576217651367187500e+01},
                    {1.15920634392383039568130698171444237232208251953125e+01, 4.81750775541114606426162936259061098098754882812500e+01},
                    {1.15918570125466846576500756782479584217071533203125e+01, 4.81750233074259952559259545523673295974731445312500e+01},
                    {1.15916491918811690453594565042294561862945556640625e+01, 4.81749934252979201687594468239694833755493164062500e+01},
                    {1.15914981699401149484174311510287225246429443359375e+01, 4.81749862996976787599123781546950340270996093750000e+01},
                    {1.15913240873582576995204362901858985424041748046875e+01, 4.81749947353188900933673721738159656524658203125000e+01},
                    {1.15911393280312786657759716035798192024230957031250e+01, 4.81750280036237228387108189053833484649658203125000e+01},
                    {1.15909743809630771949059635517187416553497314453125e+01, 4.81750881850171666087589983362704515457153320312500e+01},
                    {1.15908528663166130456829705508425831794738769531250e+01, 4.81751617935495985989291511941701173782348632812500e+01},
                    {1.15907771914438502136590614099986851215362548828125e+01, 4.81752317753107988096417102497071027755737304687500e+01},
                    {1.15907230166908039592499335412867367267608642578125e+01, 4.81753098015527854158790432848036289215087890625000e+01},
                    {1.15906875311873776013271708507090806961059570312500e+01, 4.81754092837176486341377312783151865005493164062500e+01},
                    {1.15906823952789554965647766948677599430084228515625e+01, 4.81754868778009779362037079408764839172363281250000e+01},
                    {1.15907075304032343154858608613722026348114013671875e+01, 4.81755933532826574605678615625947713851928710937500e+01},
                    {1.15908162889946222406933884485624730587005615234375e+01, 4.81757437165730522110607125796377658843994140625000e+01},
                    {1.15909431388594548195669631240889430046081542968750e+01, 4.81758328236360355845135927665978670120239257812500e+01},
                    {1.15910587831223779176070820540189743041992187500000e+01, 4.81758838431721017059317091479897499084472656250000e+01},
                    {1.15913191373139188300456225988455116748809814453125e+01, 4.81759345345272791405477619264274835586547851562500e+01},
                    {1.15914332255482648292854719329625368118286132812500e+01, 4.81759358581313250624589272774755954742431640625000e+01},
                    {1.15915487696369936543305811937898397445678710937500e+01, 4.81759267620459254999332188162952661514282226562500e+01},
                    {1.15916744774305655596435826737433671951293945312500e+01, 4.81759060965004479726303543429821729660034179687500e+01},
                    {1.15917833785235604437957590562291443347930908203125e+01, 4.81758808928819846073565713595598936080932617187500e+01},
                    {1.15919304941614349502287950599566102027893066406250e+01, 4.81758376471149603048615972511470317840576171875000e+01}
            };

            int i = 0;
            for (const auto &s : roadHighwayExitSouth.getStartCoordinates<Geometry>()) {
                projected = projector->project(roadHighwayExitSouth.getElement<Geometry>(s).getStart());
                EXPECT_NEAR(projected.distance(expected[i++]), 0, maxDifference);
            }
        }


        /**
         * Tests the creation of the google map links works.
         */
        TEST_F(ProjectorTests, testCreateGoogleLinks) {
            Vector projected;

            std::vector<std::string> expected = {
                    "https://www.google.de/maps/place/48.17760081063497779041426838375627994537353515625,11.594578774260693165842894813977181911468505859375",
                    "https://www.google.de/maps/place/48.17742521986165371572496951557695865631103515625,11.5944315382777514145118402666412293910980224609375",
                    "https://www.google.de/maps/place/48.177176788807713592177606187760829925537109375,11.594223413188188942513079382479190826416015625",
                    "https://www.google.de/maps/place/48.1768790750348188112184288911521434783935546875,11.5939725944763001308501770836301147937774658203125",
                    "https://www.google.de/maps/place/48.176670485886262440544669516384601593017578125,11.5937972010443814951941021718084812164306640625",
                    "https://www.google.de/maps/place/48.1764978341072520606758189387619495391845703125,11.593652747738435238034071517176926136016845703125",
                    "https://www.google.de/maps/place/48.1763298904701997571464744396507740020751953125,11.59351388457144338417492690496146678924560546875",
                    "https://www.google.de/maps/place/48.17621764392955441280719242058694362640380859375,11.5934190956392466631541537935845553874969482421875",
                    "https://www.google.de/maps/place/48.176116928331879307734197936952114105224609375,11.5933179874727301239545340649783611297607421875",
                    "https://www.google.de/maps/place/48.17603794127644079026140389032661914825439453125,11.593236480310878278032760135829448699951171875",
                    "https://www.google.de/maps/place/48.17592594892541768558658077381551265716552734375,11.5931242812564594402147122309543192386627197265625",
                    "https://www.google.de/maps/place/48.17577410088806999510779860429465770721435546875,11.5929930878437943420067313127219676971435546875",
                    "https://www.google.de/maps/place/48.17560037931975358560521272011101245880126953125,11.5928405792098505600051794317550957202911376953125",
                    "https://www.google.de/maps/place/48.1754243034824725100406794808804988861083984375,11.592662084448392079139011912047863006591796875",
                    "https://www.google.de/maps/place/48.17524618989042295424951589666306972503662109375,11.592425246420344109310462954454123973846435546875",
                    "https://www.google.de/maps/place/48.17514350234898046210219035856425762176513671875,11.592232975530780691997279063798487186431884765625",
                    "https://www.google.de/maps/place/48.17507755411146064261629362590610980987548828125,11.5920634392383039568130698171444237232208251953125",
                    "https://www.google.de/maps/place/48.17502330742599525592595455236732959747314453125,11.5918570125466846576500756782479584217071533203125",
                    "https://www.google.de/maps/place/48.17499342529792016875944682396948337554931640625,11.5916491918811690453594565042294561862945556640625",
                    "https://www.google.de/maps/place/48.174986299697678759912378154695034027099609375,11.5914981699401149484174311510287225246429443359375",
                    "https://www.google.de/maps/place/48.1749947353188900933673721738159656524658203125,11.5913240873582576995204362901858985424041748046875",
                    "https://www.google.de/maps/place/48.1750280036237228387108189053833484649658203125,11.591139328031278665775971603579819202423095703125",
                    "https://www.google.de/maps/place/48.17508818501716660875899833627045154571533203125,11.5909743809630771949059635517187416553497314453125",
                    "https://www.google.de/maps/place/48.17516179354959859892915119417011737823486328125,11.590852866316613045682970550842583179473876953125",
                    "https://www.google.de/maps/place/48.17523177531079880964171024970710277557373046875,11.5907771914438502136590614099986851215362548828125",
                    "https://www.google.de/maps/place/48.1753098015527854158790432848036289215087890625,11.5907230166908039592499335412867367267608642578125",
                    "https://www.google.de/maps/place/48.17540928371764863413773127831518650054931640625,11.59068753118737760132717085070908069610595703125",
                    "https://www.google.de/maps/place/48.175486877800977936203707940876483917236328125,11.5906823952789554965647766948677599430084228515625",
                    "https://www.google.de/maps/place/48.17559335328265746056786156259477138519287109375,11.5907075304032343154858608613722026348114013671875",
                    "https://www.google.de/maps/place/48.1757437165730522110607125796377658843994140625,11.5908162889946222406933884485624730587005615234375",
                    "https://www.google.de/maps/place/48.17583282363603558451359276659786701202392578125,11.590943138859454819566963124088943004608154296875",
                    "https://www.google.de/maps/place/48.175883843172101705931709147989749908447265625,11.59105878312237791760708205401897430419921875",
                    "https://www.google.de/maps/place/48.17593453452727914054776192642748355865478515625,11.5913191373139188300456225988455116748809814453125",
                    "https://www.google.de/maps/place/48.1759358581313250624589272774755954742431640625,11.59143322554826482928547193296253681182861328125",
                    "https://www.google.de/maps/place/48.17592676204592549993321881629526615142822265625,11.59154876963699365433058119378983974456787109375",
                    "https://www.google.de/maps/place/48.17590609650044797263035434298217296600341796875,11.59167447743056555964358267374336719512939453125",
                    "https://www.google.de/maps/place/48.17588089288198460735657135955989360809326171875,11.5917833785235604437957590562291443347930908203125",
                    "https://www.google.de/maps/place/48.1758376471149603048615972511470317840576171875,11.591930494161434950228795059956610202789306640625"
            };

            int i = 0;
            for (const auto &s : roadHighwayExitSouth.getStartCoordinates<Geometry>()) {
                projected = projector->project(roadHighwayExitSouth.getElement<Geometry>(s).getStart());
                ASSERT_STREQ(LongLatProjector::toGoogleMapsLink(projected).c_str(), expected[i++].c_str());
            }
        }
    }// namespace tests
}// namespace opendrive