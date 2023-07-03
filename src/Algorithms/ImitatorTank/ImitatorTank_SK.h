
// --------------------------------------------------------------------------
/*
 DO NOT EDIT THIS FILE. IT IS AUTOGENERATED FILE.
 ALL YOUR CHANGES WILL BE LOST.
 
 НЕ РЕДАКТИРУЙТЕ ЭТОТ ФАЙЛ. ЭТОТ ФАЙЛ СОЗДАН АВТОМАТИЧЕСКИ.
 ВСЕ ВАШИ ИЗМЕНЕНИЯ БУДУТ ПОТЕРЯНЫ.
*/ 
// --------------------------------------------------------------------------
// generate timestamp: 2023-06-29+03:00
// -----------------------------------------------------------------------------
#ifndef ImitatorTank_SK_H_
#define ImitatorTank_SK_H_
// -----------------------------------------------------------------------------
#include <memory>
#include <string>
#include <unordered_map>
#include <sstream>
#include "UniSetObject.h"
#include "UniXML.h"
#include "Trigger.h"
#include "DebugStream.h"
#include "LogServer.h"
#include "LogAgregator.h"
#include "VMonitor.h"
// -----------------------------------------------------------------------------
class ImitatorTank_SK:
	public uniset::UniSetObject
{
	public:
		ImitatorTank_SK( uniset::ObjectId id, xmlNode* node=uniset::uniset_conf()->getNode("ImitatorTank"), const std::string& argprefix="", xmlNode* globalConfNode=nullptr );
		ImitatorTank_SK();
		virtual ~ImitatorTank_SK();

		
		long getValue( uniset::ObjectId sid );
		void setValue( uniset::ObjectId sid, long value );
		void askSensor( uniset::ObjectId sid, UniversalIO::UIOCommand, uniset::ObjectId node = uniset::uniset_conf()->getLocalNode() );
		void updateValues();

		virtual uniset::SimpleInfo* getInfo( const char* userparam ) override;

		virtual bool setMsg( uniset::ObjectId code, bool state = true ) noexcept;

		inline std::shared_ptr<DebugStream> log() noexcept { return mylog; }
		inline std::shared_ptr<uniset::LogAgregator> logAgregator() noexcept { return loga; }

		void init_dlog( std::shared_ptr<DebugStream> d ) noexcept;

        // "синтаксический сахар"..для логов
        #ifndef myinfo 
        	#define myinfo if( log()->debugging(Debug::INFO) ) log()->info() 
        #endif
        #ifndef mywarn
	        #define mywarn if( log()->debugging(Debug::WARN) ) log()->warn()
        #endif
        #ifndef mycrit
    	    #define mycrit if( log()->debugging(Debug::CRIT) ) log()->crit()
        #endif
        #ifndef mylog1
        	#define mylog1 if( log()->debugging(Debug::LEVEL1) ) log()->level1()
        #endif
        #ifndef mylog2
	        #define mylog2 if( log()->debugging(Debug::LEVEL2) ) log()->level2()
        #endif
        #ifndef mylog3
    	    #define mylog3 if( log()->debugging(Debug::LEVEL3) ) log()->level3()
        #endif
        #ifndef mylog4
        	#define mylog4 if( log()->debugging(Debug::LEVEL4) ) log()->level4()
        #endif
        #ifndef mylog5
	        #define mylog5 if( log()->debugging(Debug::LEVEL5) ) log()->level5()
        #endif
        #ifndef mylog6
    	    #define mylog6 if( log()->debugging(Debug::LEVEL6) ) log()->level6()
        #endif
        #ifndef mylog7
        	#define mylog7 if( log()->debugging(Debug::LEVEL7) ) log()->level7()
        #endif
        #ifndef mylog8
	        #define mylog8 if( log()->debugging(Debug::LEVEL8) ) log()->level8()
        #endif
        #ifndef mylog9
    	    #define mylog9 if( log()->debugging(Debug::LEVEL9) ) log()->level9()
        #endif
        #ifndef mylogany
        	#define mylogany log()->any()
        #endif
        #ifndef vmonit
            #define vmonit( var ) vmon.add( #var, var )
        #endif
        
        // Вспомогательные функции для удобства логирования
        // ------------------------------------------------------------
        /*! вывод в строку значение всех входов и выходов в формате
           ObjectName: 
              in_xxx  = val
              in_xxx2 = val
              out_zzz = val
              ...
        */
        std::string dumpIO();
        
        /*! Вывод в строку названия входа/выхода в формате: in_xxx(SensorName) 
           \param id           - идентификатор датчика
           \param showLinkName - TRUE - выводить SensorName, FALSE - не выводить
        */
        std::string str( uniset::ObjectId id, bool showLinkName=true ) const;
        
        /*! Вывод значения входа/выхода в формате: in_xxx(SensorName)=val 
           \param id           - идентификатор датчика
           \param showLinkName - TRUE - выводить SensorName, FALSE - не выводить
        */
        std::string strval( uniset::ObjectId id, bool showLinkName=true ) const;        

        /*! Вывод в строку названия датчика-сообщения: xxx(SensorName) 
           \param id           - идентификатор датчика
           \param showLinkName - TRUE - выводить SensorName, FALSE - не выводить
        */
        std::string msgstr( uniset::ObjectId id, bool showLinkName=true ) const;

        
        /*! Вывод состояния внутренних переменных */
        inline std::string dumpVars(){ return vmon.pretty_str(); }
        // ------------------------------------------------------------
        std::string help() const noexcept;


#ifndef DISABLE_REST_API
        // HTTP API
        virtual Poco::JSON::Object::Ptr httpGet( const Poco::URI::QueryParameters& p ) override;
        virtual Poco::JSON::Object::Ptr httpRequest( const std::string& req, const Poco::URI::QueryParameters& p ) override;
        virtual Poco::JSON::Object::Ptr httpHelp( const Poco::URI::QueryParameters& p ) override;
#endif


		// Используемые идентификаторы
		
		const uniset::ObjectId SwitchOnIncLevelPump; 		/*!< Включить насос подающий жидкость в бак */
		const uniset::ObjectId node_SwitchOnIncLevelPump;
		
		const uniset::ObjectId SwitchOffIncLevelPump; 		/*!< отключить насос подающий жидкость в бак */
		const uniset::ObjectId node_SwitchOffIncLevelPump;
		
		const uniset::ObjectId SwitchOnDecLevelPump; 		/*!< включить насос откачивающий жидкость из бака */
		const uniset::ObjectId node_SwitchOnDecLevelPump;
		
		const uniset::ObjectId SwitchOffDecLevelPump; 		/*!< отключить насос откачивающий жидкоть из бака */
		const uniset::ObjectId node_SwitchOffDecLevelPump;
		
		const uniset::ObjectId WaterLevel; 		/*!< текущий уровень жидкость (в литрах) */
		const uniset::ObjectId node_WaterLevel;
		

		// Используемые идентификаторы сообщений
		

		// Текущее значение
		const long& in_SwitchOnIncLevelPump;
		const long& in_SwitchOffIncLevelPump;
		const long& in_SwitchOnDecLevelPump;
		const long& in_SwitchOffDecLevelPump;
		long out_WaterLevel;
		

		// --- public variables ---
		
		long TankSize; /*!< Размер бака (в литрах) */
		long LevelIncSpeed; /*!< Скорость заполнения (в литрах/секунду), по умолчанию - 10 л/секунду */
		long LevelDecSpeed; /*!< Скорость опустошения (в литрах/секунду), по умолчанию - 10 л/секунду */
		
		// --- end of public variables ---

	protected:
		// --- protected variables ---
		
		
		// ---- end of protected variables ----

		
		virtual void callback() noexcept override;
		virtual void processingMessage( const uniset::VoidMessage* msg ) override;
		virtual void sysCommand( const uniset::SystemMessage* sm ) override {}
		virtual void askSensors( UniversalIO::UIOCommand cmd ) {}
		virtual void sensorInfo( const uniset::SensorMessage* sm ) override {}
		virtual void timerInfo( const uniset::TimerMessage* tm ) override {}
		virtual bool activateObject() override;
		virtual bool deactivateObject() override;
		virtual std::string getMonitInfo() const { return ""; } /*!< пользовательская информация выводимая в getInfo() */
		virtual std::string getTypeOfMessage( int t ) const { return uniset::strTypeOfMessage(t); } /*!< получение названия типа сообщения. Используется в getInfo() */

#ifndef DISABLE_REST_API
		virtual void httpGetUserData( Poco::JSON::Object::Ptr& jdata ){} /*!<  для пользовательских данных в httpGet() */
        virtual Poco::JSON::Object::Ptr httpDumpIO();
        virtual Poco::JSON::Object::Ptr httpRequestLog( const Poco::URI::QueryParameters& p );
        virtual Poco::JSON::Object::Ptr request_params_set( const std::string& req, const Poco::URI::QueryParameters& p ) override;
        virtual Poco::JSON::Object::Ptr request_params_get( const std::string& req, const Poco::URI::QueryParameters& p ) override;
#endif

        // Выполнение очередного шага программы
		virtual void step(){}

		void preAskSensors( UniversalIO::UIOCommand cmd );
		void preSysCommand( const uniset::SystemMessage* sm );
		
		virtual void testMode( bool state );
		void updateOutputs( bool force );

		bool waitSM( int wait_msec, uniset::ObjectId testID = uniset::DefaultObjectId );
		uniset::ObjectId getSMTestID() const;

		void resetMsg();
		uniset::Trigger trResetMsg;
		uniset::PassiveTimer ptResetMsg;
		int resetMsgTime;

		int sleep_msec; /*!< пауза между итерациями */
		bool active;

		const std::string argprefix;
		uniset::ObjectId smTestID; /*!< идентификатор датчика для тестирования готовности SM */

		// управление датчиком "сердцебиения"
		uniset::PassiveTimer ptHeartBeat;				/*! < период "сердцебиения" */
		uniset::ObjectId idHeartBeat;		/*! < идентификатор датчика (AI) "сердцебиения" */
		long maxHeartBeat;						/*! < сохраняемое значение */
		
		xmlNode* confnode;
		/*! получить числовое свойство из конф. файла по привязанной confnode */
		int getIntProp(const std::string& name) { return uniset::uniset_conf()->getIntProp(confnode, name); }
		/*! получить текстовое свойство из конф. файла по привязанной confnode */
		inline const std::string getProp(const std::string& name) { return uniset::uniset_conf()->getProp(confnode, name); }

		uniset::timeout_t smReadyTimeout; 	/*!< время ожидания готовности SM */
		std::atomic_bool activated = { false };
		std::atomic_bool cancelled = { false };
		uniset::timeout_t activateTimeout;	/*!< время ожидания готовности UniSetObject к работе */
		uniset::PassiveTimer ptStartUpTimeout;	/*!< время на блокировку обработки WatchDog, если недавно был StartUp */
		int askPause; /*!< пауза между неудачными попытками заказать датчики */
		
		IOController_i::SensorInfo si;
		bool forceOut; /*!< флаг принудительного обнуления "выходов" */
		
		std::shared_ptr<uniset::LogAgregator> loga;
		std::shared_ptr<DebugStream> mylog;
		std::shared_ptr<uniset::LogServer> logserv;
		std::string logserv_host = {""};
		int logserv_port = {0};

		uniset::VMonitor vmon;

		

	private:
		
		// --- private variables ---
		// --- end of private variables ---

		// предыдущее значение (для работы UpdateValue())
		long prev_in_SwitchOnIncLevelPump;
		long prev_in_SwitchOffIncLevelPump;
		long prev_in_SwitchOnDecLevelPump;
		long prev_in_SwitchOffDecLevelPump;
		long prev_out_WaterLevel;
		
		
		// Текущее значение (rw-переменные)
		long priv_in_SwitchOnIncLevelPump;
		long priv_in_SwitchOffIncLevelPump;
		long priv_in_SwitchOnDecLevelPump;
		long priv_in_SwitchOffDecLevelPump;
		

		// Используемые идентификаторы сообщений
		
		// ------------ private функции ---------------
		void updatePreviousValues() noexcept;
		void preSensorInfo( const uniset::SensorMessage* sm );
		void preTimerInfo( const uniset::TimerMessage* tm );
		void initFromSM();
		void checkSensors();
		// --------------------------------------------
		
		class StatHashFn
		{
			public:
			size_t operator() (const uniset::ObjectId& key) const
			{
				return std::hash<long>()(key);
			}
		};
		
		std::unordered_map<const uniset::ObjectId,size_t, StatHashFn> smStat; /*!< количество сообщений по датчикам */
		size_t processingMessageCatchCount = { 0 }; /*!< количество исключений пойманных в processingMessage */

		std::unordered_map<long,size_t> msgTypeStat; /*!< количество сообщений по типам */

		std::string ostate = { "" }; /*!< состояние процесса (выводится в getInfo()) */
		

		bool end_private; // вспомогательное поле (для внутреннего использования при генерировании кода)
};

// -----------------------------------------------------------------------------
#endif // ImitatorTank_SK_H_
