#include "gtest/gtest.h"
#include "lib.h"


TEST(Translit, Kogda_eto_uzhe_zakonchitsya) {

    EXPECT_STREQ(translitStr("Привет"), "Privet");
    EXPECT_STREQ(translitStr("Привет мой дорогой друг"), "Privet moy dorogoy drug");
    EXPECT_STREQ(translitStr("Ёлка ёлка"), "Yolka yolka");
    EXPECT_STREQ(translitStr(""), "");
    EXPECT_STREQ(translitStr("ЪъъЪььЬЬьЬьЬ"), "");
    EXPECT_STREQ(translitStr("А Б В Г Д Е Ё Ж З И Й К Л М Н О П Р С Т У Ф Х Ц Ч Ш Щ Ы Э Ю Я"), "A B V G D E Yo Zh Z I Y K L M N O P R S T U F Kh Ts Ch Sh Sch Y E Yu Ya");
    EXPECT_STREQ(translitStr("а б в г д е ё ж з и й к л м н о п р с т у ф х ц ч ш щ ы э ю я"), "a b v g d e yo zh z i y k l m n o p r s t u f kh ts ch sh sch y e yu ya");

}

// a b v g d e yo zh z i y k l m n o p r s t u f kh ts ch sh sch y e yu ya
// a b v g d e yo zh z i y k l m n o p r s t u f Kh ts ch sh sch y e yu ya

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}