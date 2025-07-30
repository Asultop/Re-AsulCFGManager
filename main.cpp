#include "AsulCFGManager.h"

#include <QApplication>
#include <ElaApplication.h>
#include <QSplashScreen>
#include <QSettings>
#include <ElaWindow.h>
#include "Headers/T_SplashScreen.h"
#include <QTranslator>
#include <QPalette>
#include <QColor>
// 获取较暗的颜色版本（降低亮度）
QColor getDarkerColor(const QColor& color, int factor = 90) {
    // 创建颜色副本并调整亮度
    QColor result = color;
    result.setHslF(
        result.hslHueF(),
        result.hslSaturationF(),
        qMax(0.0, result.lightnessF() * (factor / 100.0)),
        result.alphaF()
        );
    return result;
}

// 获取较亮的颜色版本（提高亮度）
QColor getLighterColor(const QColor& color, int factor = 110) {
    // 创建颜色副本并调整亮度
    QColor result = color;
    result.setHslF(
        result.hslHueF(),
        result.hslSaturationF(),
        qMin(1.0, result.lightnessF() * (factor / 100.0)),
        result.alphaF()
        );
    return result;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    eApp->init();
    qApp->setAutoSipEnabled(true);


    QColor bgColor = qApp->palette().color(QPalette::Highlight);

    qDebug()<<"bgColor=" <<bgColor;

    eTheme->setThemeColor(ElaThemeType::Dark, ElaThemeType::PrimaryNormal, bgColor);
    eTheme->setThemeColor(ElaThemeType::Dark, ElaThemeType::PrimaryHover, getLighterColor(bgColor));
    eTheme->setThemeColor(ElaThemeType::Dark, ElaThemeType::PrimaryPress, getLighterColor(bgColor,105));

    eTheme->setThemeColor(ElaThemeType::Light, ElaThemeType::PrimaryNormal, bgColor);
    eTheme->setThemeColor(ElaThemeType::Light, ElaThemeType::PrimaryHover, getDarkerColor(bgColor));
    eTheme->setThemeColor(ElaThemeType::Light, ElaThemeType::PrimaryPress, getDarkerColor(bgColor,95));

    QSettings setting("HKEY_CURRENT_USER\\Software\\Asul\\AM",QSettings::NativeFormat);
    bool dark=setting.value("DarkTheme").toBool();
    QString lang=setting.value("Language").toString();
    QStringList SupportLang={"zh_CN","en_US","ru_RU"};
    int displayMode=setting.value("DisplayMode").toInt();
    eApp->setWindowDisplayMode(ElaApplicationType::Normal);
    // switch (displayMode){
    //     case 0:
    //         eApp->setWindowDisplayMode(ElaApplicationType::Normal);
    //         break;
    //     case 1:
    //         eApp->setWindowDisplayMode(ElaApplicationType::ElaMica);
    //         break;
    //     case 2:
    //         eApp->setWindowDisplayMode(ElaApplicationType::Mica);
    //         break;
    //     case 3:
    //         eApp->setWindowDisplayMode(ElaApplicationType::MicaAlt);
    //         break;
    //     case 4:
    //         eApp->setWindowDisplayMode(ElaApplicationType::Acrylic);
    //         break;
    //     case 5:
    //         eApp->setWindowDisplayMode(ElaApplicationType::DWMBlur);
    //         break;
    // }
    QTranslator translator;
    if(lang.isEmpty()&&!SupportLang.contains(lang)){

        QLocale::Language lab = QLocale::system().language();
        if(QLocale::Chinese == lab)
        {
            auto REF=translator.load(":/lang/translations/AM_zh_CN.qm");
            Q_UNUSED(REF);
            lang="zh_CN";

        }else if(QLocale::English == lab){
            auto REF=translator.load(":/lang/translations/AM_en_US.qm");
            Q_UNUSED(REF);
            lang="en_US";
        }else if(QLocale::Russian == lab){
            auto REF=translator.load(":/lang/translations/AM_ru_RU.qm");
            Q_UNUSED(REF);
            lang="ru_RU";
        }

        setting.setValue("Language",lang);
    }else{
        if(lang=="zh_CN"){
            auto REF=translator.load(":/lang/translations/AM_zh_CN.qm");
            Q_UNUSED(REF);
        }else if(lang=="en_US"){
            auto REF=translator.load(":/lang/translations/AM_en_US.qm");
            Q_UNUSED(REF);
        }else if(lang=="ru_RU"){
            auto REF=translator.load(":/lang/translations/AM_ru_RU.qm");
            Q_UNUSED(REF);
        }
    }
    qApp->installTranslator(&translator);
    QPixmap pix;
    eTheme->setThemeMode(dark?ElaThemeType::Light:ElaThemeType::Dark);
    eTheme->setThemeMode(dark?ElaThemeType::Dark:ElaThemeType::Light);
    QTimer::singleShot(500,[=](){
        eTheme->setThemeMode(dark?ElaThemeType::Light:ElaThemeType::Dark);
        eTheme->setThemeMode(dark?ElaThemeType::Dark:ElaThemeType::Light);
    });



    T_SplashScreen *splashWindow=new T_SplashScreen();



    // splashWindow->setWindowFlag(Qt::WindowStaysOnTopHint);
    // QApplication::processEvents();
    // QTimer::singleShot(500,[=](){splashWindow->show();});
    splashWindow->show();

    a.processEvents();




    Asul w;
    // w.showMinimized();
    // w.setHidden(true);
    w.setVisible(false);
    Asul::connect(eTheme,&ElaTheme::themeModeChanged,[=](ElaThemeType::ThemeMode themeMode){
        QSettings darkSet("HKEY_CURRENT_USER\\Software\\Asul\\AM",QSettings::NativeFormat);
        darkSet.setValue("DarkTheme",themeMode==ElaThemeType::Light?false:true);
    });
    QTimer::singleShot(200,[&](){
        w.show();
    });



    // eTheme->setThemeColor();

    // Asul::connect(&w,&Asul::initFinished,[=](){
    //     splashWindow->close();
    //     splashWindow->deleteLater();
    // });
    // splash.finish(&w);
    QTimer::singleShot(200,[=](){
        splashWindow->close();
        splashWindow->deleteLater();
        // aboutpage->deleteLater();
    });
    return a.exec();
}
