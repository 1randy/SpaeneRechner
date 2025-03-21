#include "Modules/module.h"

namespace  {
std::filesystem::path dynamicPath = std::filesystem::current_path() / "Daten.xlsx";
int dynamicIndex = 1;
}


class Dynamic {
public:
    static QStringList matList() {
        QStringList mat;
        int row = 2;

        xlnt::workbook wb;
        wb.load(dynamicPath);
        xlnt::worksheet ws = wb.sheet_by_index(dynamicIndex);

        while (ws.cell(1, row).to_string() != "") {
            mat.append(QString::fromStdString(ws.cell(1, row).to_string()));
            row++;
        }

        return mat;
    }

    static double Vc(int mat, int bed) {
        double Vc;
        int column = bed + 2;

        mat = mat + 2;

        xlnt::workbook wb;
        wb.load(dynamicPath);
        xlnt::worksheet ws = wb.sheet_by_index(dynamicIndex);

        Vc = ws.cell(column, mat).value<double>();

        return Vc;
    }

    static double fz(int mat, int bed, double D) {
        double fz;
        int column = 5;

        mat = mat + 2;

        column = column + bed;

        if(D > 15) {
            column = column + 3;
        }

        xlnt::workbook wb;
        wb.load(dynamicPath);
        xlnt::worksheet ws = wb.sheet_by_index(dynamicIndex);

        fz = ws.cell(column, mat).value<double>();

        return fz;
    }

    static double ae(int mat, int bed, double D) {
        double ae;
        int column = 11;

        mat = mat + 2;

        column = column + bed;

        if(D > 15) {
            column = column + 3;
        }

        xlnt::workbook wb;
        wb.load(dynamicPath);
        xlnt::worksheet ws = wb.sheet_by_index(dynamicIndex);

        ae = ws.cell(column, mat).value<double>();

        return ae;
    }

    static int Kc(int mat) {
        int Kc;

        mat = mat + 2;

        xlnt::workbook wb;
        wb.load(dynamicPath);
        xlnt::worksheet ws = wb.sheet_by_index(dynamicIndex);

        Kc = ws.cell(17, mat).value<int>();

        return Kc;
    }

    static double Mc(int mat) {
        double Mc;

        mat = mat + 2;

        xlnt::workbook wb;
        wb.load(dynamicPath);
        xlnt::worksheet ws = wb.sheet_by_index(dynamicIndex);

        Mc = ws.cell(18, mat).value<double>();

        return Mc;
    }
};
