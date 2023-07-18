

class State {
    protected: 
        ControlProcess* controlprocess;
    public:
        virtual ~State(){};
        void SetControlProcess(ControlProcess* cp){
            controlprocess = cp;
            //init();
        };

        virtual void processLogic() = 0;
        virtual void init() = 0;

};

class PumpNetralState : public State {
    public:
       // virtual ~PumpNetralState(){};
        void processLogic() override;
        void init() override;

};

class PupmOnState : public State {
    public:
       // virtual ~PupmOnState(){};
        void processLogic() override;
        void init() override;
};

class PupmOnOffState : public State {
    public:
       // virtual ~PupmOnState(){};
        void processLogic() override;
        void init() override;
};

class PupmOffState : public State {
    public:
        //virtual ~PupmOffState(){};
        void processLogic() override;
        void init() override;
};