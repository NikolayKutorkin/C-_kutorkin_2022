//
// Created by Николай on 18.02.2022.
//
class Material
{
public:
    // Принимает на вход величину деформации.
    // Возвращает величину напряжения, посчитанную с учётом реологии материала.
    virtual float getStress(float strain) = 0;
};

class ElasticMaterial: public Material {
public:
    ElasticMaterial(float elasticModulus) {
        this->elasticModulus = elasticModulus;
    }
    float getStress(float strain) {
        return elasticModulus * strain;
    }
protected:
    float elasticModulus;
};


class PlasticMaterial: public Material {
public:
    PlasticMaterial(float elasticModulus, float strainLimit) {
        this->elasticModulus = elasticModulus;
        this->strainLimit = strainLimit;
    }
    float getStress(float strain) {
        if (strain < this->strainLimit) {
            return elasticModulus * strain;
        } else {
            return elasticModulus * strainLimit;
        }
    }
protected:
    float elasticModulus;
    float strainLimit;
};
